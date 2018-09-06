#include <string>
using namespace std;

class Pedido{
  private: //Declaração de variaveis
		Mesa *mesa;
		Produto *conta;
		float valorFinal, acrescimo, desconto, total;
  public:

		void setMesa(Mesa *mesa){
			this->mesa = mesa;
		};

		void encerrarConta(){
			int quantidadeProdutos = this->conta->size();
			this->total = Produto::PRECO_BASE;
			for(indice = 0; indice < quantidadeProdutos; indice++){
				this->total += this->conta[indice]->getPreco();
			}

			if(this->mesa->tipo == 2){
				this->acrescimo = (this->total*2)/100;
			}

			this->desconto = this->total * this->mesa->cliente->getDesconto();
			this->valorFinal = (this->total + this->acrescimo) - this->desconto;
		}

		void limparConta(){
			this->conta->clear();
		}

		void incluirProduto(Produto *produto){
			this->conta->push_back(produto);
		};

		void excluirProduto(){
			int quantidadeProdutos = this->conta->size();
			cout<<"Digite o numero do produtos que deseja excluir: ";
			for(indice = 0; indice < quantidadeProdutos; indice++){
				cout << "["<< indice << "] " << this->conta[indice] << "\n";
			}
			cin >> indiceRemover;
			this->conta->erase(indiceRemover);
		}

		void gerarCupomFiscal(){
			this->encerrarConta();
			cout<<"\nValor bruto: R$"<<this->total<<"\nValor liquido: R$"<<this->valorFinal<<"\nDesconto: R$"<<this->desconto;
			if(this->mesa->tipo==2)
				{cout<<"\nAcrecimo: "<<this->acrescimo;}
			cout<<"\n";system("pause");
		};
		
};