#include <string>
using namespace std;

class PessoaJuridica : public Pessoa{
  public:
    int cnpj;

    PessoaJuridica(){}
    PessoaJuridica(string nome, string endereco, int cnpj){
      this->nome = nome;
      this->endereco = endereco;
      this->cnpj = cnpj;
    };
};