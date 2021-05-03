add_library(MathFunctions mysqrt.cxx)

# Specify modern CMake based INTERFACE usage requirements of the library:
# means things that consumers require but producer doesn't;
# Anyone linking to MathFunctions needs to include the current source directory
# to find MathFunctions.h, while MathFunctions itself doesn't
target_include_directories(
    MathFunctions
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

# settings to allow usage of new defines so as to check
# if the current platform/system provides desired functions or not
include(CheckSymbolExists)
set(CMAKE_REQUIRED_LIBRARIES "m")
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)
if(HAVE_LOG AND HAVE_EXP)
    # specify as PRIVATE compile definitions
    target_compile_definitions(
        MathFunctions
        PRIVATE "HAVE_LOG" "HAVE_EXP"
    )
endif()

# install rules (library and header file)
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
