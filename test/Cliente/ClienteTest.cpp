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

#include <string>
#include "ClienteTest.h"

void ClienteTest::setUp(){
}

void ClienteTest::tearDown(){
  delete this->cliente;
}


void ClienteTest::testClienteFisico(){
  long int cnpj = 0;
  double desconto = 0.25;

  this->cliente = new Cliente(1,"Moises", "Av. Independencia");

  CPPUNIT_ASSERT(this->cliente->pessoa->nome == "Moises");
  CPPUNIT_ASSERT(this->cliente->pessoa->endereco == "Av. Independencia");
  CPPUNIT_ASSERT_EQUAL(desconto, this->cliente->pessoa->getDesconto());
  CPPUNIT_ASSERT_EQUAL(cnpj, this->cliente->pessoa->getCnpj());
  CPPUNIT_ASSERT_EQUAL(this->cliente->tipo, TipoPessoa::FISICA);
}

void ClienteTest::testClienteJuridico(){
  long int cnpj = 68223850000192;
  double desconto = 0.0;

  this->cliente = new Cliente(1,"Moises", "Av. Independencia", cnpj);

  CPPUNIT_ASSERT(this->cliente->pessoa->nome == "Moises");
  CPPUNIT_ASSERT(this->cliente->pessoa->endereco == "Av. Independencia");
  CPPUNIT_ASSERT_EQUAL(desconto, this->cliente->pessoa->getDesconto());
  CPPUNIT_ASSERT_EQUAL(cnpj, this->cliente->pessoa->getCnpj());
  CPPUNIT_ASSERT_EQUAL(this->cliente->tipo, TipoPessoa::JURIDICA);
}


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( ClienteTest );

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