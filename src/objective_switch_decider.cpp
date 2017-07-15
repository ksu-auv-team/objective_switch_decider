#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int8.h"
#include <iostream>

using namespace std;

int current_switch_state;

void start_gate_callback(const std_msgs::String& msg)
{
    current_switch_state = 1;
}
void path_marker_1_callback(const std_msgs::String& msg)
{
    current_switch_state = 2;
}
void bouy_callback(const std_msgs::String& msg)
{
    current_switch_state = 3;
}
void path_marker_2_callback(const std_msgs::String& msg)
{
    current_switch_state = 4;
}
void channel_callback(const std_msgs::String& msg)
{
    current_switch_state = 5;
}
void hydrophone_1_callback(const std_msgs::String& msg)
{
    current_switch_state = 6;
}
void dropper_callback(const std_msgs::String& msg)
{
    current_switch_state = 7;
}
void torpedo_callback(const std_msgs::String& msg)
{
    current_switch_state = 8;
}
void hydrophone_2_callback(const std_msgs::String& msg)
{
    current_switch_state = 9;
}
void samples_callback(const std_msgs::String& msg)
{
    current_switch_state = 10;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv,"switch_decider");
    ros::NodeHandle nh;
    ros::Subscriber start_gate_sub = nh.subscribe("/sub_ai_state_manager/start_gate", 10, start_gate_callback);
    ros::Subscriber path_marker_1_sub = nh.subscribe("/sub_ai_state_manager/path_marker_1", 10, path_marker_1_callback);
    ros::Subscriber bouy_sub = nh.subscribe("/sub_ai_state_manager/bouy", 10, bouy_callback);
    ros::Subscriber path_marker_2_sub = nh.subscribe("/sub_ai_state_manager/path_marker_2", 10, path_marker_2_callback);
    ros::Subscriber channel_sub = nh.subscribe("/sub_ai_state_manager/channel", 10, channel_callback);
    ros::Subscriber hydrophone_1_sub = nh.subscribe("/sub_ai_state_manager/hydrophone_1", 10, hydrophone_1_callback);
    ros::Subscriber dropper_sub = nh.subscribe("/sub_ai_state_manager/dropper", 10, dropper_callback);
    ros::Subscriber torpedo_sub = nh.subscribe("/sub_ai_state_manager/torpedo", 10, torpedo_callback);
    ros::Subscriber hydrophone_2_sub = nh.subscribe("/sub_ai_state_manager/hydrophone_2", 10, hydrophone_2_callback);
    ros::Subscriber samples_sub = nh.subscribe("/sub_ai_state_manager/samples", 10, samples_callback);
    
    ros::Publisher decider = nh.advertise<std_msgs::Int8>("decider",10);
    ros::Rate loop_rate(10);
    while (ros::ok())
    {
        decider.publish(current_switch_state);
        ros::spinOnce();
    }
    return 0;
}
