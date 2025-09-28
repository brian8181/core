# Find CppUnit
find_package(PkgConfig REQUIRED)
pkg_check_modules(CPPUNIT REQUIRED cppunit)

# Test sources
set(TEST_SOURCES
    TestCalculator.cpp
    main.cpp
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
