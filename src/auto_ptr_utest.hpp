// # File Name:  ./Auto_Ptr__test.hpp
// # Build Date: Wed Nov  8 08:33:47 AM CST 2023
// # Version:    0.1

#ifndef _CORE_TEST_H
#define _CORE_TEST_H

#include <cppunit/Test.h>

class Core_Test : public CppUnit::TestFixture
{
private:
    CPPUNIT_TEST_SUITE(Auto_Ptr_Test);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

protected:
    void testNoOptions();

};

#endif
