using namespace std;

#include <cppunit/extensions/HelperMacros.h>
#include "../../class/Pessoa.h"
#include "../../class/PessoaJuridica.h"
#include "../../class/PessoaFisica.h"

class PessoaTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( PessoaTest );
  CPPUNIT_TEST( testConstrutorSemParametro );
  CPPUNIT_TEST( testConstrutorComParametro );
  CPPUNIT_TEST( testSetNome );
  CPPUNIT_TEST( testSetEndereco );
  CPPUNIT_TEST_SUITE_END();

  public:
    Pessoa *pessoa;

    void setUp();
    void tearDown();

    void testConstrutorSemParametro();
    void testConstrutorComParametro();
    void testSetNome();
    void testSetEndereco();
};

//endif  // PESSOATEST_H