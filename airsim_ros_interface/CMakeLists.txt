cmake_minimum_required(VERSION 3.0.2)
project(airsim_ros_interface)

# Find the required ROS packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Ensure the correct ABI is used
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)

# Include directories
include_directories(
  ${catkin_INCLUDE_DIRS}
  /home/yi/AirSim/AirLib/include
  /home/yi/AirSim/AirLib/deps/rpclib/include  # Add the rpclib include directory
  /usr/include/eigen3
)

# Add the executable
add_executable(airsim_collision_node src/airsim_collision_node.cpp)

# Link libraries
target_link_libraries(airsim_collision_node
  ${catkin_LIBRARIES}
  /home/yi/AirSim/AirLib/lib/libAirLib.a
  /home/yi/AirSim/AirLib/deps/MavLinkCom/lib/libMavLinkCom.a
  /home/yi/AirSim/AirLib/deps/rpclib/lib/librpc.a
  -lstdc++  # Use this for GCC
  #-lc++    # Uncomment this if you're using Clang instead of GCC
)


