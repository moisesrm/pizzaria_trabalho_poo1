#include <string>
using namespace std;

class PessoaJuridica : public Pessoa{
  private:
    long int cnpj;

  public:

    PessoaJuridica(){}
    PessoaJuridica(string nome, string endereco, long int cnpj){
      this->nome = nome;
      this->endereco = endereco;
      this->cnpj = cnpj;
      this->tipo = TipoPessoa::JURIDICA;
    }

    void setCnpj(long int cnpj) { this->cnpj = cnpj; }
    long int getCnpj() { return this->cnpj; }
};