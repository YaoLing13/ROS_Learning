cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Find catkin and any catlin package
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  genmsg
)

## Declare ros messages and services
#add_message_files(DIRECTORY msg FILES Num.msg)
#add_service_files(DIRECTORY srv FILES AddTwoInts.srv)

## Generate added message and services
#generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
#catkin_package(CATKIN_DEPENDS roscpp)
catkin_package(

 # INCLUDE_DIRS include
	CATKIN_DEPENDS roscpp
#  LIBRARIES pubvel
#  CATKIN_DEPENDS other_catkin_pkg

#  DEPENDS system_lib

)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker beginner_tutorials_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener beginner_tutorials_generate_messages_cpp)
