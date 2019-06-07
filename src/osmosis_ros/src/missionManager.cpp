//juil2018 J.Guiochet @ LAAS
#include <osmosis_control/missionManager.hpp>


void MissionManager::driveMissionManager()
{
	switch (state_)
	{
		case CHOICE:
			char mode;
			mode=askMode();
			if(mode=='K'||mode=='k')
				state_=KEYBOARD;
			else if(mode=='M'||mode=='m')
				state_=MISSION;
			else
				ROS_ERROR("Input Error : Please try again.\n");
			break;

		case KEYBOARD:
			goalKeyboard();
			state_=CHOICE;
			break;

		case MISSION:
			switch (missionState_)
			{
				case WAITMISSION:
					if(askMission())
						missionState_=WAITORDERDONE;
					else
					{
						ROS_ERROR("Mission Aborted");
						state_=CHOICE;
					}
					break;

				case WAITORDERDONE:
					if(this->doMission())
					{
						std::cout<<"Mission accomplie !" << std::endl;
						missionState_=WAITMISSION;
						state_=CHOICE;
					}
					break;
				
			}
			break;
        }
  }

bool MissionManager::doMission()
{
	bool missionOver=false;

	if(goal_reached_)
	{
		mission_.step++;
		if(this->isMissionOver())
		{
			missionOver=true;
		}
		else
			this->sendNextOrder();
	}

	return missionOver;
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

char MissionManager::askMode()
{
	char mode;
	std::string input;

	std::cout << std::endl << "Enter the mode : ('K':keyboard 'M':mission)" << std::endl;
	std::cin >> input;
	mode=input[0];

	return mode;
}

bool MissionManager::askMission()
{
	bool ok=false;

	std::string name;
	std::cout << "Enter the mission : " << std::endl;
	std::cin >> name;

	if(initMission(name))
	{
		ok=true;
		pub_on_=true;
		mission_.step=0;
		state_and_point_cmd_=mission_.orders[mission_.step];
	}

	return ok;
}

//! ROS node initialization
MissionManager::MissionManager()
{
	//set up the publisher for the goal topic
	goal_pub_ = nh_.advertise<osmosis_control::State_and_PointMsg>("goal", 1);
	goal_reached_sub_ = nh_.subscribe("/goal_reached", 1, &MissionManager::MissionManagerCallbackGoalReached, this); 
	goal_reached_=false;
	pub_on_=false;
	state_=CHOICE;
	missionState_=WAITMISSION;
	state_and_point_cmd_.taxi=true; // A enlever ?
}


void MissionManager::MissionManagerCallbackGoalReached(const std_msgs::Bool &goal_reached)
{
	goal_reached_=goal_reached.data;
}

void MissionManager::goalKeyboard()
{
	geometry_msgs::Point thegoal;
	std::cout << "Enter a new goal (x,y)\nx= ";
	std::cin >> thegoal.x;

	std::cout << "y= ";
	std::cin >> thegoal.y;
	state_=KEYBOARD;

	pub_on_=true;
	state_and_point_cmd_.goal=thegoal;
}

bool MissionManager::initMission(std::string name)
{
	bool ok=false;
	goal_reached_=false;

	std::cout << "Init mission" << std::endl;

	std::string filename=ros::package::getPath("osmosis_control");
	filename.append("/MISSION_" + name + ".miss");
	
	std::ifstream fichier(filename, std::ios::in);

	if(fichier)
	{

		int i;
		int taille=mission_.orders.size();
		for(i=0;i<taille;i++)
			mission_.orders.pop_back();

		std::string line;

		while(getline(fichier, line))
			parse(line);

		for(i=0; i<mission_.orders.size();i++)
		{
			std::cout<<"x:"<<mission_.orders[i].goal.x << " y:" << mission_.orders[i].goal.y;
			if(mission_.orders[i].taxi)
				std::cout << " taxi=true" << std::endl;
			else
				std::cout << " taxi=false" << std::endl;
		}
		
		ok=true;
		fichier.close();
	}

	else
		ROS_ERROR("Mission Not Found !\n");

	return ok;
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
	return this->goal_reached_;
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
  ros::init(argc, argv, "navigation_node");

  MissionManager myMManager;
  myMManager.run();
}
