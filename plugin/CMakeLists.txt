cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

project(CHANGE_DISPLAY_PLUGIN)

find_package(gazebo REQUIRED)
include_directories(${GAZEBO_INCLUDE_DIRS})
link_directories(${GAZEBO_LIBRARY_DIRS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

add_library(DisplayChangePlugin SHARED DisplayChangePlugin.cpp)
target_link_libraries(DisplayChangePlugin ${GAZEBO_LIBRARIES})

install(
  TARGETS DisplayChangePlugin
  LIBRARY DESTINATION lib
)
