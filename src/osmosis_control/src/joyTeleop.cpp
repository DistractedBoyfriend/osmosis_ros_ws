//juil2019 Anthony FAVIER / Antonin MESSIOUX @ LAAS
#include <joyTeleop.hpp>

////////////////////// PRIVATE //////////////////////

void JoyTeleop::JoyFSM()
{
	switch (state_)
	{
	 	case DESACTIVATED:
			if (button_pressed_)
			{
				state_=ACTIVATED;
				joy_on();
			}
			break;

		case ACTIVATED:
		        if(button_pressed_)
			{
			        state_=DESACTIVATED;
				joy_off();
		        }
			break;

		default: break;
	}
}

void JoyTeleop::joy_on()
{
	joy_teleop_cmd_.is_active=true;
	button_pressed_=false;
	pub_on_=true;
	ROS_INFO("Controller Activation");
}

void JoyTeleop::joy_off()
{
	joy_teleop_cmd_.is_active=false;
	button_pressed_=false;
	ROS_INFO("Controller Desactivation");
}


////////////////////// PUBLIC //////////////////////

JoyTeleop::JoyTeleop()
{
	freq_=10;

	cmd_joy_teleop_pub_ = nh_.advertise<osmosis_control::TeleopMsg>("/cmd_vel_teleop", 1);
	cmd_joystick_sub_= nh_.subscribe("/joy", 1, &JoyTeleop::teleopCallbackJoy, this);

	vector<int> buttons(11,0);
	vector<float> axes(8,0);
	sensor_msgs::Joy msg;
	msg.buttons=buttons;
	msg.axes=axes;
	joy_msg_=msg;

	joy_msg_.buttons[7]=0;
	joy_teleop_cmd_.is_active=false;
	joy_teleop_cmd_.cmd_vel.linear.x=joy_teleop_cmd_.cmd_vel.linear.y=joy_teleop_cmd_.cmd_vel.angular.z=0;
	button_pressed_=false;
	pub_on_=false;
   	state_=DESACTIVATED;
}

void JoyTeleop::run()
{
	ROS_INFO("You should now be able to activate the controller (with 'start')");
	ros::Rate loop_rate(freq_);
	while (nh_.ok())
	{
		JoyFSM();
		if(pub_on_)
		{
			cmd_joy_teleop_pub_.publish(joy_teleop_cmd_);
			if(state_==DESACTIVATED)
				pub_on_=false;
		}
	 	ros::spinOnce(); // Need to call this function often to allow ROS to process incoming messages
		loop_rate.sleep(); // Sleep for the rest of the cycle, to enforce the loop rate
	}
}

void JoyTeleop::teleopCallbackJoy(const sensor_msgs::Joy & joy_msg)
{
	// rising edge detection
	if(joy_msg_.buttons[7]==0 && joy_msg.buttons[7]==1)
		button_pressed_=true;

	joy_msg_=joy_msg;

	if(state_==ACTIVATED)
	{
		geometry_msgs::Twist base_cmd;
		float axe1, axe2;

		axe1=joy_msg_.axes[1];
		axe2=joy_msg_.axes[3];

		base_cmd.linear.x=axe1;//according to safety_pilot, max_linear=1
		base_cmd.angular.z=axe2;//and max_angular=1

		joy_teleop_cmd_.cmd_vel.linear.x=base_cmd.linear.x;
		joy_teleop_cmd_.cmd_vel.angular.z=base_cmd.angular.z;
	}
}


////////////////////// MAIN //////////////////////

int main(int argc, char** argv)
{
	//init the ROS node
	ros::init(argc, argv, "joy_teleop_node");

	JoyTeleop myJoyTeleop;
	myJoyTeleop.run();
}
