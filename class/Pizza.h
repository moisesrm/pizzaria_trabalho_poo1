#include <string>
#include <vector>
using namespace std;

class Pizza: public Produto{
  private:
    void setPreco(){
      this->preco = this->componentes->size()*0.05;
    }

    vector <Sabor> sabores;
    vector <Componente>* componentes;

  public:
    Pizza(string nome, string descricao){
      this->nome = nome;
      this->descricao = descricao;
    };

    void montar(vector <Sabor> sabores, vector <Componente>* componentes){
      this->sabores = sabores;
      this->componentes = componentes;
      this->setPreco();
    };

    float getPreco(){      
      return this->preco;
    };

    string getDetalhes(){
      return "";
    };

		// void set_pizza() //Menu com o que deseja fazer
		// 	{
		// 		int x;
		// 		char s='s';
		// 		while(s!='n')
		// 			{
		// 				system("cls");
    //         cout<<".-----------------.\n|       Menu        |\n|-------------------|\n|1.Inserir Sabor    |\n|2.Inserir Comp.    |";
		// 				cout<<"\n|3.Adc. Sabor       |\n|4.Adc. Comp.       |\n|5.Sair             |\n|___________________|\nMenu: ";cin>>x;
		// 				switch(x)
		// 					{
		// 						case 1: set_sabor();break;
		// 						case 2: set_componente();break;
		// 						case 3: adiciona_sabor();break;
		// 						case 4: adiciona_componente();break;
		// 						case 5: s='n';break;
		// 						default: cout<<"Codigo errado!";break;
		// 					}
		// 			}
		// 		cout<<"Digite a descricao da pizza: ";cin>>desc_pz;
		// 	};
    // void set_sabor() //Coloca sabor
    //   {
    //     int x,c=0,n=0;
    //     string y;
    //     cout<<"Quantos sabores de pizza deseja: ";cin>>n; //Informa quantos sabores tera a pizza
    //     sa=new sabor[n];
    //     total_s=n;
    //     system("cls");
    //     while(c<=n-1)
    //       {
    //         system("cls");
    //         cout<<".----------------.\n|    Sabores     |\n|----------------|\n|1.Calabresa     |\n|2.Bacon         |";
    //         cout<<"\n|3.Quatro Queijos|\n|4.Batata        |\n|________________|\nSabor: ";cin>>x; //Informa qual sabor
    //         switch(x)//Insere o sabor
    //           {
    //             case 1:y="Calabresa";sa[c].set_sabor(y);c++;break;
    //             case 2:y="Bacon";sa[c].set_sabor(y);c++;break;
    //             case 3:y="Quatro_Queijos";sa[c].set_sabor(y);c++;break;
    //             case 4:y="Batata";sa[c].set_sabor(y);c++;break;
    //             default:cout<<"Codigo invalido!";break;
    //           }
    //       }
    //   };
    // void set_componente() //Coloca componente
    //   {
    //     int x,c=0,n=0;
    //     string y;
    //     cout<<"Quantos componentes tera a pizza: ";cin>>n;//Informa quantos componentes tera a pizza
    //     ca=new componentes[n];
    //     total_c=n;
    //     system("cls");
    //     while(c<=n-1)
    //       {
    //         system("cls");
    //         cout<<".----------------.\n|  Componentes   |\n|----------------|\n|1.Calabresa     |\n|2.Bacon         |";
    //         cout<<"\n|3.Abacate       |\n|4.Batata        |\n|________________|\nComponente: ";cin>>x; //Informa qual componente
    //         switch(x)//Insere o componente na pizza
    //           {
    //             case 1:y="Calabresa";ca[c].set_componente(y);c++;break;
    //             case 2:y="Bacon";ca[c].set_componente(y);c++;break;
    //             case 3:y="Abacate";ca[c].set_componente(y);c++;break;
    //             case 4:y="Batata";ca[c].set_componente(y);c++;break;
    //             default:cout<<"Codigo invalido!";break;
    //           }
    //       }
    //   };
    // void adiciona_sabor() //Adiciona mais sabores
    //   {
    //     int x,c,n=0;
    //     string y;
    //     cout<<"Informe quantos sabores deseja adicionar: ";cin>>n; //Informa quantos sabores a mais tera a pizza
    //     ns=new sabor[total_s+n];
    //     for(c=0;c<total_s;c++)   {  set_novos_sabores(c,sa[c]); }
    //     total_s+=n;
    //     system("cls");
    //     while(c<=total_s-1)//Adiciona apenas o numero de sabores a mais
    //       {
    //         system("cls");
    //         cout<<".----------------.\n|    Sabores     |\n|----------------|\n|1.Calabresa     |\n|2.Bacon         |";
    //         cout<<"\n|3.Quatro Queijos|\n|4.Batata        |\n|________________|\nSabor: ";cin>>x;//Escolhe o sabor
    //         switch(x)//Insere o sabor
    //           {
    //             case 1:y="Calabresa";ns[c].set_sabor(y);c++;break;
    //             case 2:y="Bacon";ns[c].set_sabor(y);c++;break;
    //             case 3:y="Quatro_Queijos";ns[c].set_sabor(y);c++;break;
    //             case 4:y="Batata";ns[c].set_sabor(y);c++;break;
    //             default:cout<<"Codigo invalido!";break;
    //           }
    //       }
    //       sa=new sabor[total_s];
    //       for(c=0;c<total_s;c++)   {  set_sabores(c,ns[c]); }
    //       delete ns;
    //   };
    // void adiciona_componente()//Adiciona mais componentes
    //   {
    //     int x,c,n=0;
    //     string y;
    //     cout<<"Informe quantos componentes deseja adicionar: ";cin>>n;//Informa quantos componentes a mais tera a pizza
    //     nc=new componentes[total_c+n];
    //     for(c=0;c<total_c;c++)   {  set_novos_componentes(c,ca[c]); }
    //     total_c+=n;
    //     system("cls");
    //     while(c<=total_c-1)//Adiciona apenas o numero de componentes a mais
    //       {
    //         system("cls");
    //         cout<<".----------------.\n|    Sabores     |\n|----------------|\n|1.Calabresa     |\n|2.Bacon         |";
    //         cout<<"\n|3.Abacate       |\n|4.Batata        |\n|________________|\nSabor: ";cin>>x; //Informa o componente
    //         switch(x)//Adiciona o componente a pizza
    //           {
    //             case 1:y="Calabresa";nc[c].set_componente(y);c++;break;
    //             case 2:y="Bacon";nc[c].set_componente(y);c++;break;
    //             case 3:y="Abacate";nc[c].set_componente(y);c++;break;
    //             case 4:y="Batata";nc[c].set_componente(y);c++;break;
    //             default:cout<<"Codigo invalido!";break;
    //           }
    //       }
    //       ca=new componentes[total_c];
    //       for(c=0;c<total_c;c++)   {  set_componentes(c,nc[c]); }
    //       delete nc;
    //   };
    // void set_novos_sabores(int x,sabor n){ns[x]=n;}; //Função para adicionar novos sabores
    // void set_sabores(int x,sabor n){sa[x]=n;};//Função para retorna os valores dos sabores adicionados
    // void set_novos_componentes(int x,componentes n){nc[x]=n;};//Função para adicionar novos componentes
    // void set_componentes(int x,componentes n){ca[x]=n;};//Função para retorna os valores dos componentes adicionados
		// void get_pizza(int x){cout<<sa[x].get_sabor()<<ca[x].get_componente();};//Função para retorna o sabor e o componente
		// string get_desc_pz(){return desc_pz;};//Função para retorna a descrição da pizza
};