/**
 * @file offb_node.cpp
 * @brief Offboard control example node, written with MAVROS version 0.19.x, PX4 Pro Flight
 * Stack and tested in Gazebo SITL
 */

#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/CommandTOL.h>

using namespace std;

geometry_msgs::PoseStamped current_pose;
geometry_msgs::PoseStamped pose;

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

void current_pose_cb(const geometry_msgs::PoseStamped::ConstPtr& msg){
    current_pose = *msg;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 10, state_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            ("mavros/setpoint_position/local", 10);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");
    ros::ServiceClient takeoff_command_client = nh.serviceClient<mavros_msgs::CommandTOL>
	    ("mavros/cmd/takeoff");
    ros::Subscriber current_position_sub = nh.subscribe<geometry_msgs::PoseStamped>
	    ("mavros/local_position/pose", 10, current_pose_cb);

    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    ROS_INFO("INITILIZING...");
    for(int i=0; i<100; i++) {
	ros::spinOnce();
	ros::Duration(0.01).sleep();
    }

    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }

    pose.pose.position.x = 10;
    pose.pose.position.y = 10;
    pose.pose.position.z = 20;

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "GUIDED";


    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i){
        local_pos_pub.publish(pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    while(ros::ok()){
        if(current_state.mode != "GUIDED" && (ros::Time::now() - last_request > ros::Duration(5.0))){
            if(set_mode_client.call(offb_set_mode) && offb_set_mode.response.mode_sent){
                ROS_INFO("GUIDED enabled");
		break;
            }
            last_request = ros::Time::now();
        }
        ros::spinOnce();
        rate.sleep();
    }

    while(ros::ok()){
        if(!current_state.armed && (ros::Time::now() - last_request > ros::Duration(5.0))){
            if(arming_client.call(arm_cmd) && arm_cmd.response.success){
                ROS_INFO("UAV Armed");
		break;
            }
            last_request = ros::Time::now();
        }
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::CommandTOL takeoff_request;
    takeoff_request.request.altitude = 1.5;
    while (!takeoff_request.response.success) {
	ros::Duration(.1).sleep();
	if(ros::Time::now() - last_request > ros::Duration(0.5)){
            takeoff_command_client.call(takeoff_request);
            last_request = ros::Time::now();
        }
	ros::spinOnce();
        rate.sleep();
    }
    ROS_INFO("Takeoff initialized");
    ros::Duration(10).sleep();
    double tolerance = 0.35;

    if (local_pos_pub) {
	for (int i = 10000; ros::ok() && i > 0; --i) {
		local_pos_pub.publish(pose);
		float deltaX = abs(pose.pose.position.x - current_pose.pose.position.x);
		float deltaY = abs(pose.pose.position.y - current_pose.pose.position.y);
		float deltaZ = abs(pose.pose.position.z - current_pose.pose.position.z);
		float dMag = sqrt( pow(deltaX, 2) + pow(deltaY, 2) + pow(deltaZ, 2) );
		cout << dMag << endl;
		if( dMag < tolerance) {
			break;
		}
      		ros::spinOnce();
     		ros::Duration(0.5).sleep();
      		if(i == 1) {
        		ROS_INFO("Failed to reach destination. Stepping to next task.");
      		}
    	}
    	ROS_INFO("Done moving foreward.");
    }

  //land
  ros::ServiceClient land_client = nh.serviceClient<mavros_msgs::CommandTOL>("/mavros/cmd/land");
  mavros_msgs::CommandTOL srv_land;
  if (land_client.call(srv_land) && srv_land.response.success) {
      ROS_INFO("land sent %d", srv_land.response.success);
  } else {
      ROS_ERROR("Landing failed");
      ros::shutdown();
      return -1;
  }
  return 0;
}
