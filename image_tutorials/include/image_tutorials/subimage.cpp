#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <iostream>

void imageCallback(const sensor_msgs::ImageConstPtr& tem_msg)
{
    try {
        cv::imshow("Get Image", cv_bridge::toCvShare(tem_msg)->image);  //ros_image to opencv_image
        cv::waitKey(27);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("Can't convert from '%s' to 'mono8'.", tem_msg->encoding.c_str());
    }
}

int main(int argc, char ** argv)
{
    ros::init(argc, argv, "subimage");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    image_transport::Subscriber sub = it.subscribe("srcImage", 1, imageCallback);

    ros::spin();

    return 0;
}