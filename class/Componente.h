#include <string>
using namespace std;

class Componente: public Produto{
  public:
    Componente(string nome, string descricao){ 
      this->nome = nome; 
      this->descricao = descricao; 
      this->preco = 0.05;
    };

    float getPreco(){
      return this->preco;
    };
};