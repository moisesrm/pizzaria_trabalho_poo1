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
  cliente = new Cliente();
}

void ClienteTest::tearDown(){
  delete cliente;
};


void ClienteTest::testClienteFisico(){
  PessoaFisica *pessoa_fisica = new PessoaFisica("Moises", "Av. Independencia");
  cliente = new Cliente();
  cliente->cadastro_cliente_fisico(1,*pessoa_fisica);

  CPPUNIT_ASSERT(cliente->pessoa->nome == "Moises");
  CPPUNIT_ASSERT(cliente->pessoa->endereco == "Av. Independencia");
}

void ClienteTest::testClienteJuridico(){
  PessoaJuridica *pessoa_juridica = new PessoaJuridica("Moises", "Av. Independencia", 68223850000192);
  cliente = new Cliente();
  cliente->cadastro_cliente_juridico(1,*pessoa_juridica);

  CPPUNIT_ASSERT(cliente->pessoa->nome == "Moises");
  CPPUNIT_ASSERT(cliente->pessoa->endereco == "Av. Independencia");
  // CPPUNIT_ASSERT(cliente->pessoa->cnpj == 68223850000192);
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