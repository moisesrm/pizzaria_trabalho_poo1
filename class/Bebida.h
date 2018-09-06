#include <string>
using namespace std;

class Bebida: public Produto{
  public:
    Bebida(string nome, string descricao){ 
      this->preco = 5.00;
      this->nome = nome; 
      this->descricao = descricao; 
    };

    float getPreco(){
      return this->preco;
    }
};