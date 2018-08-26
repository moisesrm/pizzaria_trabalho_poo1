
#include <string>
#include <vector>

using namespace std;

class Produto{
  protected:
    float preco;

	private:
		int codigo;
		
	public:
    const float PRECO_BASE = 20.00;
    string nome, descricao;

    Produto(){}
    Produto(string nome, string descricao){
      this->nome;
      this->descricao;
    }

    virtual void setPreco(){};
    virtual float getPreco(){};
    virtual string getDetalhes(){};
};
