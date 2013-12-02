cmake_minimum_required(VERSION 2.8.3)
project(spin_turtle)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs geometry_msgs)

## The catkin_package macro generates cmake config files for your package
catkin_package(
    CATKIN_DEPENDS roscpp std_msgs geometry_msgs
)

include_directories(${catkin_INCLUDE_DIRS})

## Add executable spin_turtle
add_executable(spin_turtle src/spin_turtle.cpp)
target_link_libraries(spin_turtle ${catkin_LIBRARIES})
add_dependencies(spin_turtle ${catkin_EXPORTED_TARGETS})
