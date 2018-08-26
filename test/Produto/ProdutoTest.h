using namespace std;

#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include <vector>
#include "../../class/Pizza.h"
#include "../../class/Bebida.h"

class ProdutoTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( ProdutoTest );
  CPPUNIT_TEST( testAdicionarPizza );
  CPPUNIT_TEST( testAdicionarBebida );
  CPPUNIT_TEST( testAdicionarComponente );
  CPPUNIT_TEST_SUITE_END();

  private:
    vector <Produto> cardapio;
    vector <Componente> componentes;
    vector <Sabor> sabores;

  public:
    void setUp();
    void tearDown();
    
    void testAdicionarPizza();
    void testAdicionarBebida();
    void testAdicionarComponente();

};

//endif  // PESSOATEST_H