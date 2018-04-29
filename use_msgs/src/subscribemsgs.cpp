#include <ros/ros.h>
#include <test_msgs/Num.h>
#include <iostream>
#include <string>

void messageCallback(const test_msgs::Num::ConstPtr &msg)
{
	std::vector<float> array = msg->data;
	std::cout << "msg->data[0]=" << msg->data[0] << std::endl;
  std::cout << "msg->data.size=" << msg->data.size() << std::endl;
  std::cout << "msg->data=" << msg->data[0] << ", " << msg->data[1] <<  ", " << msg->data[2] << ", " <<  msg->data[3] << ", " <<  msg->data[4] << ", " <<  msg->data[5] << std::endl;
}

int main(int argc, char ** argv)
{
	ros::init(argc, argv, "sub");	//node name
	ros::NodeHandle n;
	ros::Subscriber msg_sub = n.subscribe("test_msg", 1000, messageCallback);
	
	ros::spin();
	return 0;
}
