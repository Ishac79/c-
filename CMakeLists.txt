cmake_minimum_required(VERSION 3.5)
project(qtwmain)

find_package(Qt5Widgets REQUIRED)

add_executable(qtwmain main.cpp)
target_link_libraries(qtwmain Qt5::Widgets)

