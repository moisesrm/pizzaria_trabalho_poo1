#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

//Classes
#include "class/Cliente.h"
#include "class/Mesa.h"
#include "class/Bebida.h"
#include "class/Componente.h"
#include "class/Produto.h"
#include "class/Pizza.h"
#include "class/Menu.h"

using namespace std;

class Menu{
  public:
    
    function menuMesa(Mesa &mesa){ 
      int opcao = 0;
      cout << "1. Cadastrar\n2.Editar\n3.Excluir\nEscolha uma opção: ";
      while((opcao >= 3) || (opcao <= 0)){
        cin >> opcao;
        switch(opcao){
          case 1: break;
          case 2: break;
          case 3: break;
          case default: "Opção invalida\n"; break;
        }
      }
    }

    function menuCliente(vector <Clientes> *clientes){ 
      int opcao = 0;
      cout << "1. Cadastrar\n2.Editar\n3.Excluir\nEscolha uma opção: ";
      while((opcao >= 3) || (opcao <= 0)){
        cin >> opcao;
        switch(opcao){
          case 1: 
            string nome, endereco, cnpj;
            char temCnpj;
            long int cnpj;
            Pessoa *pessoa;

            cout << "Nome: ";
            cin >> nome;
            cout << "Endereco: ";
            cin >> endereco;
            cout << "Tem CNPJ ? (S/N): ";
            cin >> temCNPJ;
            if(temCNPJ == "S"){
              cout << "CNPJ: ";
              cin >> cnpj;
              pessoa = PessoaJuridica(nome, endereco, cnpj);
            }else{
              pessoa = PessoaFisica(nome, endereco);
            }

            Cliente *novoCliente = new Cliente(rand()%1001,pessoa);
            clientes->push(novoCliente);
            cout << "Cadastro feito com Sucesso !\n";
          break;
          case 2: 
            for(int indice; indice < clientes->size(); indice++){
              cout << indice << ". " << clientes[indice]->pessoa->nome << "\n";
            }

          break;
          case 3: break;
          case default: "Opção invalida\n"; break;
        }
      }
    }

    function menuProduto(vector <Produto> &produtos, vector <Sabor> &sabores){
      int opcao = 0;
      cout << "1. Cadastrar\n2.Editar\n3.Excluir\n4.Sair\nEscolha uma opção: ";
      while((opcao >= 3) || (opcao <= 0)){
        cin >> opcao;
        switch(opcao){
          case 1: 
            string nome, descricao;
            cout << "Digite o nome do produto: ";
            cin >> nome;
            cout << "Digite a descricao do produto: ";
            cin >> descricao;
            cout << "1. Bebida\n2. Componente\n3. Pizza\n4.Sair";
            opcao = 0;
            while((opcao >= 3) || (opcao <= 0)){
              cin >> opcao;
              switch(opcao){
                case 1: produto[0]->push(new Bebida(nome,descricao)); break;
                case 2: produto[1]->push(new Componente(nome,descricao)); break;
                case 3: 
                  Pizza *pizza = new Pizza(nome,descricao);
                  
                  //COMPONENTES
                  cout << "Monte a pizza\n\nEscolha os componente:\n\n\n"
                  int opcao_componente = 0;
                  for(int indice; indice < produto[2]->size(); indice++){
                    cout << indice << ". " << produto[2][indice]->nome << "\n";
                  }
                  cout << "0. Sair";
                  cin << opcao_componente;
                  vector <Componente> *componentes;
                  while(opcao_componente > 0){
                    cin << opcao_componente;
                    componentes->push(produto[2][opcao_componente]);
                  }

                  //SABORES
                  cout << "\n\nEscolha os sabores:\n\n\n"
                  int opcao_sabor = 0;
                  for(int indice; indice < sabores->size(); indice++){
                    cout << indice << ". " << sabores[indice]->nome << "\n";
                  }
                  cout << "0. Sair";
                  cin << opcao_sabor;
                  vector <Sabor> *sabor;
                  while(opcao_sabor > 0){
                    cin << opcao_sabor;
                    sabor->push(produto[2][opcao_sabor]);
                  }
                  pizza->montar(sabor, *componentes)
                  produto[2]->push(pizza);
                  break;
                case 4: break;
                case default: "Opção invalida\n"; opcao = 0; break;
              }
            }
          break;
          case 2: break;
          case 3: break;
          case 4: break;
          case default: "Opção invalida\n"; break;
        }
      }
    }

    function menuAtendimento(Mesa &mesa){
      int opcao = 0;
      cout << "1. Cadastrar\n2.Editar\n3.Excluir\nEscolha uma opção: ";
      while((opcao >= 3) || (opcao <= 0)){
        cin >> opcao;
        switch(opcao){
          case 1: break;
          case 2: break;
          case 3: break;
          case default: "Opção invalida\n"; break;
        }
      }
    }
};