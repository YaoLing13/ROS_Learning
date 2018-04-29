#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
//#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "pubimage");  //node name: pubimage
    ros::NodeHandle nh; //node handle
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub = it.advertise("srcImage", 1);
    //image_transport::Subscriber sub = it.subscribe("grayImage", 1, imageCallback);
    cv::Mat image = cv::imread("/home/yl/1work/cat.jpg", CV_LOAD_IMAGE_COLOR);
    cv::waitKey(27);
    sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg(); //opencv_image to ros_image
    int number=0;
    ros::Rate loop_rate(5);
    while(nh.ok())
    {
        number++;
        ROS_INFO("[%d]", number);
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
