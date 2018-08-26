#include <string>
#include "Cliente.h"
using namespace std;


enum class Status { OCUPADA, DISPONIVEL };

class Mesa{
  public:
    int numero;
    Cliente *cliente;
    Status status;
    string descricao, tipo;

    Mesa(int numero, string descricao, string tipo){ 
      this->numero = numero; 
      this->status = Status::DISPONIVEL; 
      this->descricao = descricao;
      this->tipo = tipo;
    }

    void reservar(Cliente *cliente){
      this->cliente = cliente;
      this->status = Status::OCUPADA;
    }

    void liberar(){
      delete this->cliente;
      this->status = Status::DISPONIVEL;
    }

    // void set_mesa () //Insere os dados da mesa
    //   {
		// 		system("cls");
    //     cout<<"Digite o numero da mesa: ";cin>>numero;
    //     cout<<"Informe o tipo da mesa: ";cin>>tipo;
    //     cout<<"Descricao: ";cin>>desc;
    //   };

    // void get_mesa() //Mostra os dados da mesa
    //   {
		// 		system("cls");
    //     cout<<"Numero: "<<numero<<"\nTipo: "<<tipo<<"\nDescricao: "<<desc<<"\nDisponibilidade: "<<disp<<"\n";
    //     if(disp == "ocupada"|| disp == "reservada")         { cout<<"Codigo do cliente: "<<cod_c<<"\n";  }
		// 		system("pause");
    //   };

		// int get_cod_c(){return cod_c;};	//Retorna o codigo do cliente

    // void set_disp() //Ocupa ou reserva mesa
    //   {
		// 		system("cls");
    //     cout<<"Informe o cod do cliente : ";cin>>cod_c;
    //     cout<<"Informe se esta disponivel, ocupada ou reservada: ";cin>>disp;
		// 		cout<<"Reserva feita com sucesso!";
    //   };
		// string get_tipo(){return tipo;}; //Retorna tipo da mesa
};
