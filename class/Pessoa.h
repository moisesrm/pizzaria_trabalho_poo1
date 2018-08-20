#include <string>
using namespace std;

class Pessoa{
    protected:
        long int cnpj;
        double desconto;

    public:
        string nome, endereco;

        Pessoa(){}
        Pessoa(string nome, string endereco, double desconto = 0, long int cnpj = 0){
            this->nome = nome;
            this->endereco = endereco;
            this->desconto = desconto;
            this->cnpj = cnpj;
        }

        virtual void addDesconto() {}
        virtual double getDesconto() { return 0; }
        virtual void setCnpj(long int cnpj) {}
        virtual long int getCnpj() { return 0; }
};