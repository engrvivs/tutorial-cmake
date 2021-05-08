# add the library that runs
add_library(MathFunctions MathFunctions.cxx)

# Specify modern CMake based INTERFACE usage requirements of the library:
# means things that consumers require but producer doesn't;
# Anyone linking to MathFunctions needs to include the current source directory
# to find MathFunctions.h, while MathFunctions itself doesn't
target_include_directories(
    MathFunctions
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
)

# option to use or not this custom (MathFunctions) library
# this setting is stored in the cache
option(USE_MYMATH, "User tutorial provided math implementation" ON)

# make building and linking the MathFunctions library conditional
if(USE_MYMATH)

    target_compile_definitions(MathFunctions PRIVATE "USE_MYMATH")

    # add executable that generates table
    add_executable(MakeTable MakeTable.cxx)

    # custom command to run MakeTable
    add_custom_command(
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h 
        COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
        DEPENDS MakeTable
    )

    # library that just does sqrt
    # let CMake know that mysqrt.cxx depends on the generated file, Table.h
    # by adding it to the list of sources for the library
    add_library(
        SqrtLibrary STATIC
        mysqrt.cxx
        ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    )

    # library depends on the binary directory to find Table.h
    # add the current binary directory to the list of include directories
    # for mysqrt.cxx to find and include Table.h
    target_include_directories(
        SqrtLibrary
        PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
    )

    # SqrtLibrary need position independent code (PIC)
    # when default is shared libraries
    set_target_properties(
        SqrtLibrary PROPERTIES
        POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
    )

    target_link_libraries(
        MathFunctions
        PRIVATE SqrtLibrary
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

endif()

#define the symbol stating we are using the declspec(dllexport) when
# building on windows
target_compile_definitions(
    MathFunctions
    PRIVATE "EXPORTING_MYMATH"
)

# install rules (library and header file)
set(installable_libs MathFunctions)
if(TARGET SqrtLibrary)
    list(APPEND installable_libs SqrtLibrary)
endif()
install(TARGETS ${installable_libs} DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)
