//juil2018 J.Guiochet @ LAAS
#include <osmosis_control/missionManager.hpp>

void MissionManager::driveMissionManager()
{
	switch (state_)
	{
		case IDLE:
			ROS_INFO("IDLE\n");
			if(hmi_mission_)
			{
				state_=MISSION;
				hmi_mission_=false;
				hmi_point_=false;
			}
			else if(hmi_point_)
			{
				state_=POINT;	
				hmi_mission_=false;
				hmi_point_=false;
			}
			break;

		case POINT:
			ROS_INFO("POINT\n");
			switch (pointState_)
			{
				case TARGETPOINT:
					ROS_INFO("TARGETPOINT\n");
					goalKeyboard();
					pointState_=WAITPOINT;
					break;
				
				case WAITPOINT:
					ROS_INFO("WAITPOINT\n");
					if(goal_reached_)
					{
						pointDone();
						pointState_=TARGETPOINT;
						state_=IDLE;
					}
					break;
			}
			break;
		

		case MISSION:
			ROS_INFO("MISSION\n");
			switch (missionState_)
			{
				case INITMISSION:
					ROS_INFO("INITMISSION\n");
					this->initMission(mission_name_);
					missionState_=EXECUTEMISSION;
					break;

				case EXECUTEMISSION:
					ROS_INFO("EXECUTEMISSION\n");
					this->doMission();
					if(missionAborted_)
					{
						abortMission();
						missionState_=INITMISSION;
						state_=IDLE;
					}

					else if(missionOver_)
					{
						missionDone();
						std::cout<<"Mission done !" << std::endl;
						missionState_=INITMISSION;
						state_=IDLE;
					}
					break;
			}
			break;
        }
}

void MissionManager::pointDone()
{
	osmosis_control::Hmi_DoneMsg done;
	done.mission=false;
	done.point=true;
	hmi_done_pub_.publish(done);
}

void MissionManager::abortMission()
{
	missionAborted_=false;

	osmosis_control::Hmi_DoneMsg done;
	done.mission=true;
	done.point=false;
	hmi_done_pub_.publish(done);
}

void MissionManager::missionDone()
{
	osmosis_control::Hmi_DoneMsg done;
	done.mission=true;
	done.point=false;
	hmi_done_pub_.publish(done);
}

void MissionManager::doMission()
{
	if(ros::Time::now()-timeStartMission_>timeout_)
	{
		missionAborted_=true;
		missionOver_=true;
	}

	else if(goal_reached_)
	{
		mission_.step++;
		if(this->isMissionOver())
		{
			missionOver_=true;
		}
		else
			this->sendNextOrder();
	}
}

bool MissionManager::isMissionOver()
{
	bool over=false;;

	if(mission_.step==mission_.orders.size())
		over=true;

	return over;
}

void MissionManager::sendNextOrder()
{
	pub_on_=true;
	goal_reached_=false;
	state_and_point_cmd_=mission_.orders[mission_.step];
}

//! ROS node initialization
MissionManager::MissionManager()
{
	//set up the publisher for the goal topic
	goal_pub_ = nh_.advertise<osmosis_control::State_and_PointMsg>("goal", 1);
	hmi_done_pub_ = nh_.advertise<osmosis_control::Hmi_DoneMsg>("hmi_done", 1);
	goal_reached_sub_ = nh_.subscribe("/goal_reached", 1, &MissionManager::MissionManagerCallbackGoalReached, this);
	emergency_sub_ = nh_.subscribe("/emergency_shutdown", 1, &MissionManager::MissionManagerCallbackEmergencyHit, this);
	hmi_order_sub_ = nh_.subscribe("/order", 1, &MissionManager::MissionManagerCallbackOrder, this);

	goal_reached_=false;
	pub_on_=false;
	state_=IDLE;
	missionState_=INITMISSION;
	pointState_=TARGETPOINT;
	state_and_point_cmd_.taxi=true;
	missionAborted_=false;
	missionOver_=true;
	hmi_point_=false;
	hmi_mission_=false;
	timeStartMission_=ros::Time::now();
	timeout_=ros::Duration(30*60); // Timeout after the mission is stopped
}


void MissionManager::MissionManagerCallbackGoalReached(const std_msgs::Bool &goal_reached)
{
	goal_reached_=goal_reached.data;
}

void MissionManager::MissionManagerCallbackEmergencyHit(const std_msgs::Bool &emergency_hit)
{
	missionAborted_=emergency_hit.data;
	missionOver_=emergency_hit.data;
}

void MissionManager::MissionManagerCallbackOrder(const osmosis_control::Hmi_OrderMsg &order)
{
	if(order.doMission)
	{
		ROS_INFO("MISSION\n");

		hmi_mission_=true;
		hmi_point_=false;
		mission_name_=order.mission_name;
	}

	else
	{
		ROS_INFO("POINT\n");

		hmi_mission_=false;
		hmi_point_=true;
		state_and_point_cmd_=order.state_and_point;
	}
}

void MissionManager::goalKeyboard()
{
	goal_reached_=false;
	pub_on_=true;
	hmi_mission_=false;
	hmi_point_=false;
}

void MissionManager::initMission(std::string name)
{
	goal_reached_=false;

	std::cout << "Init mission" << std::endl;

	std::string filename=ros::package::getPath("osmosis_control");
	filename.append("/MISSION_" + name + ".miss");

	int i;
	int taille=mission_.orders.size();
	for(i=0;i<taille;i++)
		mission_.orders.pop_back();

	std::ifstream fichier(filename, std::ios::in);
	std::string line;

	while(getline(fichier, line))
		parse(line);
	fichier.close();


	for(i=0; i<mission_.orders.size();i++)
	{
		std::cout<<"x:"<<mission_.orders[i].goal.x << " y:" << mission_.orders[i].goal.y;
		if(mission_.orders[i].taxi)
			std::cout << " taxi=true" << std::endl;
		else
			std::cout << " taxi=false" << std::endl;
	}

	timeStartMission_=ros::Time::now();
	missionOver_=false;
	mission_.step=0;
	pub_on_=true;
	state_and_point_cmd_=mission_.orders[mission_.step];
}

void MissionManager::parse(std::string line)
{
	osmosis_control::State_and_PointMsg order;

	if(line.size()>=14)
	{
		int coma=line.find(',');
		if(coma>=0)
		{
			int coma2=line.find(',', coma+1);
			if(coma2>=0)
			{
				order.goal.x=stof(line.substr(2, coma-2));
				order.goal.y=stof(line.substr(coma+3, coma2-coma-3));
				order.taxi=stoi(line.substr(coma2+6,1))!=0;

				mission_.orders.push_back(order);
			}
		}
	}
}

bool MissionManager::is_goal_reached()
{
	return goal_reached_;
}

void MissionManager::run()
{
	ros::Rate loop_rate(10); //using 10 makes the robot oscillating trajectories, TBD check with the PF algo ?
	while (nh_.ok())
	    {
		this->driveMissionManager();
		if(pub_on_)
		{
			goal_pub_.publish(state_and_point_cmd_);
			pub_on_=false;
		}
	 	ros::spinOnce(); // Need to call this function often to allow ROS to process incoming messages
		loop_rate.sleep(); // Sleep for the rest of the cycle, to enforce the loop rate
	    }
}

int main(int argc, char** argv)
{
	//init the ROS node
	ros::init(argc, argv, "mission_manager_node");

	MissionManager myMManager;
	myMManager.run();
}
