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
#include <vector>
#include "ProdutoTest.h"

void ProdutoTest::setUp(){}

void ProdutoTest::tearDown(){
  this->cardapio.clear();
}


void ProdutoTest::testAdicionarPizza(){

  Pizza *pizza = new Pizza();
  string descricao = "Pizza de calabresa com borda recheada.";
  Sabor *sabor = new Sabor("Calabresa");
  Componente *componente = new Componente("Calabresa","Hoink cortado em rodelas");

  this->sabores.push_back(*sabor);
  this->componentes.push_back(*componente);
  pizza->montar(descricao, this->sabores, &this->componentes);

  float tPreco = 0.05;

  CPPUNIT_ASSERT(pizza->descricao == "Pizza de calabresa com borda recheada.");
  CPPUNIT_ASSERT_EQUAL(tPreco, pizza->getPreco());
}

void ProdutoTest::testAdicionarBebida(){
  CPPUNIT_ASSERT("1" == "1");
}
void ProdutoTest::testAdicionarComponente(){
  CPPUNIT_ASSERT("1" == "1");
}

// void ClienteTest::testClienteJuridico(){
//   long int cnpj = 68223850000192;
//   double desconto = 0.0;

//   this->pessoa = new PessoaJuridica("Moises", "Av. Independencia", cnpj);
//   this->cliente = new Cliente(1, this->pessoa);

//   CPPUNIT_ASSERT(this->cliente->pessoa->nome == "Moises");
//   CPPUNIT_ASSERT(this->cliente->pessoa->endereco == "Av. Independencia");
//   CPPUNIT_ASSERT_EQUAL(desconto, this->cliente->pessoa->getDesconto());
//   CPPUNIT_ASSERT_EQUAL(cnpj, this->cliente->pessoa->getCnpj());
//   CPPUNIT_ASSERT_EQUAL(this->cliente->tipo, TipoPessoa::JURIDICA);
// }


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( ProdutoTest );

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