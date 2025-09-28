#include "TestCalculator.h"
#include <stdexcept>

CPPUNIT_TEST_SUITE_REGISTRATION(TestCalculator);

void TestCalculator::setUp() {
    calculator = new Calculator();
}

void TestCalculator::tearDown() {
    delete calculator;
}

void TestCalculator::testAdd() {
    CPPUNIT_ASSERT_EQUAL(5, calculator->add(2, 3));
    CPPUNIT_ASSERT_EQUAL(-1, calculator->add(-5, 4));
    CPPUNIT_ASSERT_EQUAL(0, calculator->add(0, 0));
}

void TestCalculator::testSubtract() {
    CPPUNIT_ASSERT_EQUAL(1, calculator->subtract(3, 2));
    CPPUNIT_ASSERT_EQUAL(-9, calculator->subtract(-5, 4));
    CPPUNIT_ASSERT_EQUAL(0, calculator->subtract(5, 5));
}

void TestCalculator::testMultiply() {
    CPPUNIT_ASSERT_EQUAL(6, calculator->multiply(2, 3));
    CPPUNIT_ASSERT_EQUAL(-20, calculator->multiply(-5, 4));
    CPPUNIT_ASSERT_EQUAL(0, calculator->multiply(0, 100));
}

void TestCalculator::testDivide() {
    CPPUNIT_ASSERT_DOUBLES_EQUAL(2.5, calculator->divide(5.0, 2.0), 0.001);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(-1.25, calculator->divide(-5.0, 4.0), 0.001);
}

void TestCalculator::testDivideByZero() {
    CPPUNIT_ASSERT_THROW(calculator->divide(5.0, 0.0), std::invalid_argument);
}
