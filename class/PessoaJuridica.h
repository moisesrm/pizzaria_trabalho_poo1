#include <string>
using namespace std;

class PessoaJuridica : public Pessoa{
  public:

    PessoaJuridica(){}
    PessoaJuridica(string nome, string endereco, long int cnpj):Pessoa(nome, endereco, 0.00, cnpj){}

    long int setCnpj(long int cnpj) { this->cnpj = cnpj; }
    long int getCnpj() { return this->cnpj; }
};