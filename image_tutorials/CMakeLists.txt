cmake_minimum_required(VERSION 2.8.3)
project(image_tutorials)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)
find_package(OpenCV REQUIRED)

catkin_package(
  CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
)

include_directories( ${catkin_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})

add_executable(pubimage src/pubimage.cpp)
target_link_libraries(pubimage ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(subimage src/subimage.cpp)
target_link_libraries(subimage ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(image_converter src/image_converter.cpp)
target_link_libraries(image_converter ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
