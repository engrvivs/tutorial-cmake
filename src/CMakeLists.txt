cmake_minimum_required(VERSION 3.16.3)

#set the project name and its version
project(
    Tutorial
    VERSION 0.3.0
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# configure a header file to pass the version # to the source code;
# configured file will be written into the binary tree (thus, added later)
configure_file(TutorialConfig.h.in TutorialConfig.h)

# add the executable
add_executable(Tutorial tutorial.cxx)

# add binary tree directory to the list of paths to search for include files
target_include_directories(
    Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"
)
