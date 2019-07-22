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

#ifndef OSMOSIS_MISSION_MANAGER_HPP
#define OSMOSIS_MISSION_MANAGER_HPP

#include <iostream>
#include <ros/ros.h>
#include <fstream>
#include <vector>
#include <string>
#include <ros/package.h>
#include "std_msgs/Bool.h"
#include "osmosis_control/MissionMsg.h"

using namespace std;

struct Mission
{
	string name;
	int step;
	vector<osmosis_control::GoalMsg> mission_steps;
};

class MissionManager
{
private:
	///////// Attributes ////////
	ros::NodeHandle nh_;
	ros::Publisher goal_pub_;
	ros::Publisher hmi_done_pub_;
	ros::Subscriber goal_reached_sub_;
	ros::Subscriber hmi_order_sub_;

	enum StateDriveMission{IDLE,REACH_POINT_MISSION,RUNWAY_MISSION};
	StateDriveMission state_;
	enum StateMission {INIT_MISSION,EXECUTE_MISSION};
	StateMission missionState_;
	StateMission pointState_;

	osmosis_control::GoalMsg goal_cmd_;
	Mission mission_;
	string mission_name_;

	bool goal_reached_;
	bool missionOver_;
	bool missionAborted_;
	bool hmi_point_;
	bool hmi_mission_;

	ros::Time timeStartMission_;
	ros::Duration timeout_;

	std_msgs::Bool done_;

	/////////  Methods   ////////
	void MissionManagerFSM();

	void resetIdle();
	bool isGoalReached();

	void goalKeyboard();
	void endPoint();

  void initMission(string name);
	void parse(string line);
	void doMission();
	bool checkNextOrder();
	bool isMissionOver();
	void nextOrder();
	void abortMission();
	void endMission();

	void publishMissionGoal();
	void publishDone();

public:
	MissionManager();
	void run();

	void CallbackGoalReached(const std_msgs::Bool &goal_reached);
	void CallbackOrder(const osmosis_control::MissionMsg &order);

}; // end of class

#endif
