#include <string>
using namespace std;

class PessoaFisica : public Pessoa{
  private:
    double desconto;

  public:  
  
    PessoaFisica() {}
    PessoaFisica(string nome, string endereco){
      this->nome = nome;
      this->endereco = endereco;
      this->desconto = 0.25;
      this->tipo = TipoPessoa::FISICA;
    }

    void addDesconto() { this->desconto += 0.25; }
    double getDesconto() { return this->desconto; }
};