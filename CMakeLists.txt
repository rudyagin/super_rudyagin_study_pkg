
cmake_minimum_required(VERSION 3.8)
project(super_rudyagin_study_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(time_printer src/time_printer.cpp)
ament_target_dependencies(time_printer rclcpp)

add_executable(even_number_publisher src/even_number_publisher.cpp)
ament_target_dependencies(even_number_publisher rclcpp std_msgs)

add_executable(overflow_listener src/overflow_listener.cpp)
ament_target_dependencies(overflow_listener rclcpp std_msgs)

install(TARGETS time_printer even_number_publisher overflow_listener
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
