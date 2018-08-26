using namespace std;

#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include "../../class/Mesa.h"

class MesaTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( MesaTest );
  CPPUNIT_TEST( testAdicionaMesa );  
  CPPUNIT_TEST( testReservaMesa );
  CPPUNIT_TEST_SUITE_END();

  private:
    Pessoa *pessoa;
    Cliente *cliente;
    Mesa *mesa;

  public:
    void setUp();
    void tearDown();

    void testAdicionaMesa();
    void testReservaMesa();
};

//endif  // PESSOATEST_H