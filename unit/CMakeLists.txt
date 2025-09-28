cmake_minimum_required(VERSION 3.10)
project(CppUnitExample)

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
    src/Calculator.cpp
)

# Create library from sources
add_library(${PROJECT_NAME}_lib ${SOURCES})

# Enable testing
enable_testing()

# Add tests subdirectory
add_subdirectory(tests)
