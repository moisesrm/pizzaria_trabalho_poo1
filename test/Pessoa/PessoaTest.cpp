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

#include "PessoaTest.h"

void PessoaTest::setUp(){
  pessoa = new Pessoa();
}

void PessoaTest::tearDown(){
  delete pessoa;
};

void PessoaTest::testConstrutorSemParametro(){
  pessoa = new Pessoa();
  CPPUNIT_ASSERT(pessoa->nome == "");
  CPPUNIT_ASSERT(pessoa->endereco == "");
}

void PessoaTest::testConstrutorComParametro(){
  pessoa = new Pessoa("Moises", "Av. Independencia");
  CPPUNIT_ASSERT(pessoa->nome == "Moises");
  CPPUNIT_ASSERT(pessoa->endereco == "Av. Independencia");
}

void PessoaTest::testSetNome(){
  pessoa->nome = "Moises";
  CPPUNIT_ASSERT(pessoa->nome == "Moises");
}

void PessoaTest::testSetEndereco(){
  pessoa->endereco = "Av. Independencia";
  CPPUNIT_ASSERT(pessoa->endereco == "Av. Independencia");
}

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( PessoaTest );

//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}