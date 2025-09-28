
# File Name:  streamy/src/CMakeLists.txt
# Build Date: Wed Mar  6 08:41:13 AM CST 2024
# Version:    0.1.0

cmake_minimum_required(VERSION 3.5)
project(core)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(PkgConfig REQUIRED)
pkg_check_modules(CPPUNIT REQUIRED cppunit)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add source files
set(SOURCES
    src/fileio.cpp
)

# Create library from sources
add_library(${PROJECT_NAME}_lib ${SOURCES})

# Enable testing
enable_testing()

# Test sources
set(TEST_SOURCES
    src/TestFile.cpp
    src/main.cpp
)

# Create test executable
add_executable(unit_tests ${TEST_SOURCES})

# Link libraries
target_link_libraries(unit_tests
    ${PROJECT_NAME}_lib
    ${CPPUNIT_LIBRARIES}
)

# Include directories
target_include_directories(unit_tests PRIVATE ${CPPUNIT_INCLUDE_DIRS})
# Compiler flags
target_compile_options(unit_tests PRIVATE ${CPPUNIT_CFLAGS_OTHER})
# Add test to CTest
add_test(NAME UnitTests COMMAND unit_tests)





#set(BUILD_SHARED_LIBS YES)
add_executable(core
    src/main.cpp
    src/core.cpp
    src/fileio.cpp
    src/utility.cpp
)

add_executable(core_test
    src/core_test.cpp
    src/fileio.cpp
    src/utility.cpp
)


include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281) # 10.2.1
FetchContent_MakeAvailable(fmt)
target_link_libraries(<your-target> fmt::fmt)

find_package(fmt)
target_link_libraries(<your-target> fmt::fmt)

add_subdirectory(fmt)
target_link_libraries(<your-target> fmt::fmt)



# # add_library(streamy_so SHARED
# #     streamy.cpp
# # )

add_library(core_a STATIC
    src/fileio.cpp
    src/utility.cpp
)

# target_link_libraries(core
#      STATIC core_a
#  )

#[=[
    # Add Library
    add_library(targetName [STATIC | SHARED | MODULE]
    [EXCLUDE_FROM_ALL]
    source1 [source2 ...]
)
]=]

#[=[
install(TARGETS MyApp AlgoRuntime AlgoSDK
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
]=]
