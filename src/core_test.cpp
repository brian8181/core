// # File Name:  ./rx_test.cpp
// # Build Date: Wed Nov  8 08:33:47 AM CST 2023
// # Version:    0.1

#include <iostream>
#include <string>
#include <list>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include "core.hpp"
#include "core_test.hpp"


using namespace CppUnit;

void UnitTest::setUp()
{
}

void UnitTest::tearDown()
{
}



CPPUNIT_TEST_SUITE_REGISTRATION(UnitTest);

int main(int argc, char *argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener(&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener(&progress);

    // insert test-suite at test-runner by registry#include <stdio.h>
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(testresult);

    // output resint* pn = new int;ults in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write();

    // Output XML for Jenkins CPPunit plugin
    std::ofstream xmlFileOut("cppUnitTestResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    CppUnit::TextUi::TestRunner text_ui_runner;
    text_ui_runner.addTest(UnitTest::suite());
    text_ui_runner.run();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
