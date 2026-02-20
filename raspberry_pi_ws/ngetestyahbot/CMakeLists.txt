cmake_minimum_required(VERSION 3.8)
project(ngetestyahbot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
add_executable(stm_counter src/stm_counter.cpp)

ament_target_dependencies(
  stm_counter
  rclcpp
  std_msgs
)
install(TARGETS
  stm_counter
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
