#include <ros/ros.h>
#include <test_msgs/Num.h>
#include <iostream>
#include <string>

int main(int argc, char ** argv)
{
	ros::init(argc, argv, "pub");	//node name: pub
	ros::NodeHandle nh;
	ros::Publisher msg_pub = nh.advertise<test_msgs::Num>("test_msg", 1000);
	ros::Rate loop_rate(10);
	int count = 0;
	
	while(ros::ok())
	{
		test_msgs::Num msg;
		std::cout << "msg.data.size=" << msg.data.size() << std::endl;
		
		//用vector给float32[]数组赋值
		float array[3] = {1.1, 1.2, 1.3};
		std::vector<float> array1(array, array+3);
		msg.data = array1;
		std::cout << "msg.data3[0]=" << msg.data[0] << std::endl;
    std::cout << "msg.data3.size=" << msg.data.size() << std::endl;
		float array4[4] = {1.0,2.0,0.3,6.6};
    std::vector<float> array41(array4,array4+4);
    msg.data = array41;
    std::cout << "msg.data4.size=" << msg.data.size() << std::endl;
    std::cout << "msg.data4=" << msg.data[0] << " " << msg.data[1] <<  " " << msg.data[2] << " " <<  msg.data[3] << std::endl;

    msg.data.push_back(5.5);
    std::cout << "msg.data[5]=" << msg.data[4] << std::endl;
    
    //使用迭代器
    msg.data.resize(6);
    std::cout << "msg.data6.size=" << msg.data.size() << std::endl;
    std::cout << "msg.data6=" ;
    for(std::vector<float>::iterator it = msg.data.begin(); it != msg.data.end(); ++it)
    {
      *it = 0.6;
      std::cout << *it << " ";
    }
    std::cout << std::endl;

    msg_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
	}
	return 0;
}
