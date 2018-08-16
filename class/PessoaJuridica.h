#include "Pessoa.h"

class PessoaJuridica : public Pessoa{
  public:
    int cnpj;

    PessoaJuridica(){}
    PessoaJuridica(string nome, string endereco, cnpj){
      this->tipo = "juridica";
      this->nome = nome;
      this->endereco = endereco;
      this->cnpj = cnpj;
    };
};