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
#include "MesaTest.h"

void MesaTest::setUp(){  }

void MesaTest::tearDown(){
  delete this->mesa;
}


void MesaTest::testAdicionaMesa(){
  this->mesa = new Mesa(1, "Mesa estilo americano", "Madeira");
  CPPUNIT_ASSERT(this->mesa->descricao == "Mesa estilo americano");
  CPPUNIT_ASSERT(this->mesa->tipo == "Madeira");
  CPPUNIT_ASSERT_EQUAL(1, this->mesa->numero);
}

void MesaTest::testReservaMesa(){
  this->pessoa = new Pessoa("Moises", "Av. Independencia");
  this->cliente = new Cliente(1, this->pessoa);
  this->mesa->reservar(this->cliente);

  CPPUNIT_ASSERT(this->mesa->status == Status::OCUPADA);
  CPPUNIT_ASSERT(this->mesa->cliente->pessoa->nome == "Moises");
  CPPUNIT_ASSERT_EQUAL(this->cliente->tipo, TipoPessoa::FISICA);
}


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( MesaTest );

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