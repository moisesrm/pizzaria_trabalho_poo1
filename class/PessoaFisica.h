#include "Pessoa.h"

class PessoaFisica : public Pessoa{
  public:
    float desconto;
    
    PessoaFisica(){}
    PessoaFisica(string nome, string endereco){
      this->nome = endereco;
      this->endereco = endereco;
      this->desconto = 0.25;
    };
		
    void add_desconto (){ desconto += 0.25; };
};