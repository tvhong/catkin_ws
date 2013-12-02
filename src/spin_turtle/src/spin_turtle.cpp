#include "ros/ros.h"
#include <cstdlib>
#include "geometry_msgs/Twist.h"

void generate_new_msg(geometry_msgs::Twist &msg) {
    msg.linear.x = (double) rand() / RAND_MAX * 2;
    msg.linear.y = (double) 0;
    msg.linear.z = (double) 0;
    if (rand() < RAND_MAX / 4)
        msg.linear.x *= -1;

    msg.angular.x = (double) 0;
    msg.angular.y = (double) 0;
    msg.angular.z = (double) rand() / RAND_MAX * 2;
    if (rand() > RAND_MAX / 2)
        msg.angular.z *= -1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        ROS_INFO("Usage: spin_turtle <topic>");
        return 1;
    }

    ros::init(argc, argv, "spin_turtle");
    ros::NodeHandle n;

    ros::Publisher turtle_commander = n.advertise<geometry_msgs::Twist>(argv[1], 1000);
    ros::Rate loop_rate(1);

    int cnt = 0;
    geometry_msgs::Twist msg;
    srand(time(NULL));
    while (ros::ok()) {
        if (!cnt) {
            cnt = rand() % 3 + 1;
            generate_new_msg(msg);
        }
        
        turtle_commander.publish(msg);
        ROS_INFO("Move boy");

        ros::spinOnce();
        loop_rate.sleep();
        cnt--;
    }
    return 0;
}
