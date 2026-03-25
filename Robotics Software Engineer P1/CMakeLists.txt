cmake_minimum_required(VERSION 3.5)

project(nicholas_sim_plugin)

find_package(gazebo REQUIRED)

include_directories(
  ${GAZEBO_INCLUDE_DIRS}
)

link_directories(
  ${GAZEBO_LIBRARY_DIRS}
)

add_definitions(${GAZEBO_CXX_FLAGS})

add_library(nicholas_world_initializer SHARED src/nicholas_initializer.cpp)

target_link_libraries(nicholas_world_initializer
  ${GAZEBO_LIBRARIES}
)