/*
 * Copyright 2018 LAAS-CNRS
 *
 * This file is part of the OSMOSIS project.
 *
 * Osmosis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * Osmosis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef OSMOSIS_HMI_HPP
#define OSMOSIS_HMI_HPP

#include <iostream>
#include <ros/ros.h>
#include <fstream>
#include <string>
#include <ros/package.h>
#include "std_msgs/Bool.h"
#include "osmosis_control/State_and_PointMsg.h"
#include "osmosis_control/Hmi_OrderMsg.h"

using namespace std;

class HMI
{
private:
	///////// Attributes /////////
	ros::NodeHandle nh_;
	double freq_;
	ros::Publisher orders_pub_;
	ros::Subscriber done_sub_;

	enum StateDriveHMI{IDLE,POINT,MISSION};
	StateDriveHMI state_;
	enum StateMission {ASKMISSION,WAITMISSION};
	StateMission missionState_;
	enum StatePoint {ASKPOINT,WAITPOINT};
	StatePoint pointState_;

	osmosis_control::Hmi_OrderMsg order_cmd_;

	bool goal_reached_;
	bool mission_done_;

	/////////  Methods   ////////
	void HMI_FSM();

	void ordersDone();
	char askMode();
	void goalKeyboard();
	bool askMission();
	bool checkMission(std::string name);
	void publishOrder();

public:
	HMI();
	void run();

	void CallbackOrderDone(const std_msgs::Bool &done);
};

#endif
