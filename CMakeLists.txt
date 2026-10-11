cmake_minimum_required(VERSION 3.8)
project(super_rudyagin_study_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

add_executable(time_printer src/time_printer.cpp)
ament_target_dependencies(time_printer rclcpp)

install(TARGETS time_printer
    DESTINATION lib/${PROJECT_NAME}
)

ament_package()
