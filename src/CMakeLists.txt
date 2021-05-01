cmake_minimum_required(VERSION 3.16.3)

#set the project name and its version
project(Tutorial)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add the executable
add_executable(Tutorial tutorial.cxx)
