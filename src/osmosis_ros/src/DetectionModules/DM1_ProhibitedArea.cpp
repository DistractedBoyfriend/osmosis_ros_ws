#include <osmosis_control/DetectionModules/DM1_ProhibitedArea.hpp>

//! ROS node topics publishing and subscribing initialization
DM1_ProhibitedArea::DM1_ProhibitedArea() : DetectionModule()
{
	state_sub_  = nh_.subscribe("inProhibitedArea", 1, &DM1_ProhibitedArea::DM1_ProhibitedAreaCallback, this);
 	state_=false;
}

void DM1_ProhibitedArea::set()
{
	
}

//compute detection out of zone
void DM1_ProhibitedArea::detect()
{
	// Done in a separate node
}

//Topic callback
void DM1_ProhibitedArea::DM1_ProhibitedAreaCallback(const std_msgs::Bool & state)
{
	state_ = state.data;
}
