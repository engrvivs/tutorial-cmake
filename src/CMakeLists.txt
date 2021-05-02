cmake_minimum_required(VERSION 3.16.3)

#set the project name and its version
project(
    Tutorial
    VERSION 0.5.1
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# option to use or not custom (MathFunctions) library
# this setting is stored in the cache
option(USE_MYMATH, "User tutorial provided math implementation" ON)

# configure a header file to pass few CMake settings (ver #) to the source code
# configured file will be written into the binary tree (thus, added later)
configure_file(TutorialConfig.h.in TutorialConfig.h)

# make building and linking the MathFunctions library conditional
if(USE_MYMATH)
    # add the MathFunctions library, to build it
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
    # As MathFunctions usage requirement is specified, 
    # thus, ${EXTRA_INCLUDES} can be removed.
endif()

# add the executable
add_executable(Tutorial tutorial.cxx)

# link the library to the executable, to include the library's header file
target_link_libraries(
    Tutorial PUBLIC
    ${EXTRA_LIBS}
)

# add binary tree directory to the search paths list for include files
# to find TutorialConfig.h
# As MathFunctions usage requirement is specified, 
# thus, ${EXTRA_INCLUDES} can be removed.
target_include_directories(
    Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"
)
