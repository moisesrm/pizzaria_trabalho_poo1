using namespace std;

#include <cppunit/extensions/HelperMacros.h>
#include <string>
#include "../../class/Cliente.h"

class ClienteTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( ClienteTest );
  CPPUNIT_TEST( testClienteJuridico );
  CPPUNIT_TEST( testClienteFisico );
  CPPUNIT_TEST_SUITE_END();

  private:
    Pessoa *pessoa;
    Cliente *cliente;

  public:
    void setUp();
    void tearDown();

    void testClienteJuridico();
    void testClienteFisico();
};

//endif  // PESSOATEST_H