cmake_minimum_required(VERSION 2.8.3)
project(test_msgs)

find_package(catkin REQUIRED roscpp rospy std_msgs geometry_msgs message_generation)	#message_generation对msg和srv都起作用

#增加消息依赖项
add_message_files(FILES Num.msg)

#增加service依赖项
add_service_files(FILES AddTwoInts.srv)

#消息文件所依赖的那些含有.msg文件的package(这个例子是依赖std_msgs，不要添加roscpp,rospy)
#generate_messages()
generate_messages(DEPENDENCIES std_msgs geometry_msgs)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES test_msgs
CATKIN_DEPENDS message_runtime
#  DEPENDS system_lib
)

include_directories(
# include
 ${catkin_INCLUDE_DIRS}
)

