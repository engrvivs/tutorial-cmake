add_library(MathFunctions mysqrt.cxx)

# Specify modern CMake based INTERFACE usage requirements of the library:
# means things that consumers require but producer doesn't;
# Anyone linking to MathFunctions needs to include the current source directory
# to find MathFunctions.h, while MathFunctions itself doesn't
target_include_directories(
    MathFunctions INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
