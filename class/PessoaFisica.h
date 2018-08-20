#include <string>
using namespace std;

class PessoaFisica : public Pessoa{
  public:  
  
    PessoaFisica() {}
    PessoaFisica(string nome, string endereco, double desconto = 0.25):Pessoa(nome, endereco, desconto){}

    void addDesconto() { this->desconto += 0.25; }
    double getDesconto() { return this->desconto; }
};