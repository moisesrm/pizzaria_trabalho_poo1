#include <string>

class Pessoa{
    public:
        string nome, endereco;

        Pessoa(){}
        Pessoa(string nome, string endereco){
            this->nome = nome;
            this->endereco = endereco;
        }
};