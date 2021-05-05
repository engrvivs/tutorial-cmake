# add executable that generates table
add_executable(MakeTable MakeTable.cxx)

# custom command to run MakeTable
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h 
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
)

# let CMake know that mysqrt.cxx depends on the generated file, Table.h
# by adding it to the list of sources for the library, MathFunctions
add_library(
    MathFunctions 
    mysqrt.cxx
    ${CMAKE_CURRENT_BINARY_DIR}/Table.h
)

# Specify modern CMake based INTERFACE usage requirements of the library:
# means things that consumers require but producer doesn't;
# Anyone linking to MathFunctions needs to include the current source directory
# to find MathFunctions.h, while MathFunctions itself doesn't
target_include_directories(
    MathFunctions
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    # add the current binary directory to the list of include directories
    # for mysqrt.cxx to find and include Table.h
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
)

# settings to allow usage of new defines so as to check
# if the current platform/system provides desired functions or not
include(CheckSymbolExists)
set(CMAKE_REQUIRED_LIBRARIES "m")
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)
if(HAVE_LOG AND HAVE_EXP)
# Commented this part to use table, instead (step 6)
##    # specify as PRIVATE compile definitions
##    target_compile_definitions(
##        MathFunctions
##        PRIVATE "HAVE_LOG" "HAVE_EXP"
##    )
endif()

# install rules (library and header file)
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
