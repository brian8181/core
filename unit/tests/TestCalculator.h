#ifndef TESTCALCULATOR_H
#define TESTCALCULATOR_H

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Calculator.h"

class TestCalculator : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestCalculator);
    CPPUNIT_TEST(testAdd);
    CPPUNIT_TEST(testSubtract);
    CPPUNIT_TEST(testMultiply);
    CPPUNIT_TEST(testDivide);
    CPPUNIT_TEST(testDivideByZero);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() override;
    void tearDown() override;

protected:
    void testAdd();
    void testSubtract();
    void testMultiply();
    void testDivide();
    void testDivideByZero();

private:
    Calculator* calculator;
};

#endif // TESTCALCULATOR_H
