cmake_minimum_required(VERSION 2.8.3)
project(image_rotate_demo)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs

  sensor_msgs
  cv_bridge
  image_transport
)

find_package(OpenCV REQUIRED)

catkin_package(CATKIN_DEPENDS
  roscpp
  std_msgs

  sensor_msgs
  cv_bridge
  image_transport
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

add_executable(image_processer_node
  src/image_processer_node.cpp
)
target_link_libraries(image_processer_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}

)

add_executable(image_publisher_node
  src/image_publisher_node.cpp
)
target_link_libraries(image_publisher_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBRARIES}
)
