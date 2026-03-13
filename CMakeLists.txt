cmake_minimum_required(VERSION 3.23)

project(fireList)

add_executable(fireList)

target_sources(fireList PRIVATE src/main.cpp src/Task.cpp src/TaskManager.cpp)