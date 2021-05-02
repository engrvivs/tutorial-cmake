cmake_minimum_required(VERSION 3.16.3)

#set the project name and its version
project(
    Tutorial
    VERSION 0.5.4
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

# install rules for the application (executable and configured header)
install(TARGETS Tutorial DESTINATION bin)
install(
    FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
    DESTINATION include
)

## Testing Support - S ##
enable_testing()

# does the application run (does NOT segfault or crash and returns 0)?
add_test(NAME Runs COMMAND Tutorial 25)

# does the usage message work?
add_test(NAME Usage COMMAND Tutorial)
set_tests_properties(Usage
    PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
)

# define a function to simplify adding tests
function(do_test target arg result)
    # run the application and verify results
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# do a bunch of result based tests
do_test(Tutorial 4 "4 is 2")
do_test(Tutorial 9 "9 is 3")
do_test(Tutorial 5 "5 is 2.236")
do_test(Tutorial 7 "7 is 2.645")
do_test(Tutorial 25 "25 is 5")
do_test(Tutorial -25 "-25 is [-nan|nan|0]")
do_test(Tutorial 0.0001 "0.0001 is 0.01")
## Testing Support - E ##
