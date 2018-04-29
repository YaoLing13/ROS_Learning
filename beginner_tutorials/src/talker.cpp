#include "ros/ros.h"	//include all headers necessary  of the ros system
#include "std_msgs/String.h"	//include String.msg file

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "talker");	//initialize ros, "talker" is the node name, node name must be unique in the running system(the project)

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;	//create the handle to this process' node. the last one destructed（自毁） the nodes.

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);	//tell the master we are going to publishing a message of type std_msgs::String on the topic chatter. the second arguement(1000) is the size of our publishing queue.
//NodeHanlde::advertise() - n.advertise return a ros::Publisher object. 

  ros::Rate loop_rate(10);	//allows you to specify a frequency that you would like to loop at.

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
  int count = 0;	//count of how many messages we have sent
  while (ros::ok())	// 1.ctrl-c return false.	2.eixt the same name of node. 3.ros::shutdown()	4.all ros::Handles have been destroy
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());	// output on terminal, replacement for print/cout.

    /**
     * The publish() function is how you send messages. The parameter
     * is the message object. The type of this object must agree with the type
     * given as a template parameter to the advertise<>() call, as was done
     * in the constructor above.
     */
    chatter_pub.publish(msg);	//broadcast the message to anyone who is connected

    ros::spinOnce();	//for subscription.if not, your callback (function) will never get called. so add it for good measure.

    loop_rate.sleep();	//sleep for the time remaining to let us hit our 10Hz publish rate.
    ++count;
  }


  return 0;
}
