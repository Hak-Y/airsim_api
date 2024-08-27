#include "ros/ros.h"
#include "std_msgs/String.h"
#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "airsim_collision_node");
    ros::NodeHandle nh;

    msr::airlib::MultirotorRpcLibClient client;
    client.confirmConnection();

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        auto collision_info = client.simGetCollisionInfo();
        if (collision_info.has_collided)
        {
            ROS_WARN("Collision detected with object: %s", collision_info.object_name.c_str());
        }

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}

