cmake_minimum_required(VERSION 2.8.3)
project(beginner_tutorials)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp rospy std_msgs message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
    FILES
    Num.msg
)

## Generate services in the 'srv' folder
add_service_files(
    FILES
    AddTwoInts.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
)

catkin_package(
   CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

## Build talker and listener
add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker beginner_tutorials_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener beginner_tutorials_generate_messages_cpp)

## Build add_two_ints server and client
add_executable(add_two_ints_service src/add_two_ints_service.cpp)
target_link_libraries(add_two_ints_service ${catkin_LIBRARIES})
add_dependencies(add_two_ints_service beginner_tutorials_generate_messages_cpp)

add_executable(add_two_ints_client src/add_two_ints_client.cpp)
target_link_libraries(add_two_ints_client ${catkin_LIBRARIES})
add_dependencies(add_two_ints_client beginner_tutorials_generate_messages_cpp)




# add_dependencies(talker ${catkin_EXPORTED_TARGETS})
