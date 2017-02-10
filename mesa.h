
class mesa //Class mesa
{
  private:  //Declaração de variaveis
    int numero,cod_c;
    string disp,desc,tipo;
  public:
    mesa() //Contrutor pra iniciar os parametros
      {
        numero=0;
        cod_c=0;
        disp="disponivel";
        desc="";
        tipo="";
      }
    void set_mesa () //Insere os dados da mesa
      {
				system("cls");
        cout<<"Digite o numero da mesa: ";cin>>numero;
        cout<<"Informe o tipo da mesa: ";cin>>tipo;
        cout<<"Descricao: ";cin>>desc;
      };
    void get_mesa() //Mostra os dados da mesa
      {
				system("cls");
        cout<<"Numero: "<<numero<<"\nTipo: "<<tipo<<"\nDescricao: "<<desc<<"\nDisponibilidade: "<<disp<<"\n";
        if(disp == "ocupada"|| disp == "reservada")         { cout<<"Codigo do cliente: "<<cod_c<<"\n";  }
				system("pause");
      };
		int get_cod_c(){return cod_c;};	//Retorna o codigo do cliente
    void set_disp() //Ocupa ou reserva mesa
      {
				system("cls");
        cout<<"Informe o cod do cliente : ";cin>>cod_c;
        cout<<"Informe se esta disponivel, ocupada ou reservada: ";cin>>disp;
				cout<<"Reserva feita com sucesso!";
      };
		string get_tipo(){return tipo;}; //Retorna tipo da mesa
};
