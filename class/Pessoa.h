#include <string>
using namespace std;

enum class TipoPessoa { FISICA, JURIDICA }; 

class Pessoa{
    public:
        string nome, endereco;
        TipoPessoa tipo;

        Pessoa(){}
        Pessoa(string nome, string endereco){
            this->nome = nome;
            this->endereco = endereco;
        }

        virtual void setDesconto(float desconto){}
        virtual void addDesconto(){}
        virtual double getDesconto(){ return 0; }
        virtual void setCnpj(long int cnpj){}
        virtual long int getCnpj(){}
};