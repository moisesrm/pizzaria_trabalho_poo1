
class componentes//Classe componentes
{
  protected://Declaração de variavel
    string c;
  public:
    componentes(){c="";}; //Construtor para iniciar o parametro
    void set_componente(string y){c=y;}; //Insere o nome do componente
    string get_componente(){return c;}; //Retorna o componente
};

class sabor//Classe sabor
{
  private:
    string s;//Declaração da variavel
  public:
    sabor(){s="";}; //Construtor para iniciar o parametro
    void set_sabor(string y){s=y;};//Insere o nome do sabor
    string get_sabor(){return s;};//Retorna o sabor
};

class pizza //Classe pizza
{
  protected: //Declaração de variaveis
    int total_s,total_c;
    sabor *sa,*ns;
    componentes *ca,*nc;
		string desc_pz;
  public:
		void set_pizza() //Menu com o que deseja fazer
			{
				int x;
				char s='s';
				while(s!='n')
					{
						system("cls");
            cout<<".-----------------.\n|       Menu        |\n|-------------------|\n|1.Inserir Sabor    |\n|2.Inserir Comp.    |";
						cout<<"\n|3.Adc. Sabor       |\n|4.Adc. Comp.       |\n|5.Sair             |\n|___________________|\nMenu: ";cin>>x;
						switch(x)
							{
								case 1: set_sabor();break;
								case 2: set_componente();break;
								case 3: adiciona_sabor();break;
								case 4: adiciona_componente();break;
								case 5: s='n';break;
								default: cout<<"Codigo errado!";break;
							}
					}
				cout<<"Digite a descricao da pizza: ";cin>>desc_pz;
			};
    void set_sabor() //Coloca sabor
      {
        int x,c=0,n=0;
        string y;
        cout<<"Quantos sabores de pizza deseja: ";cin>>n; //Informa quantos sabores tera a pizza
        sa=new sabor[n];
        total_s=n;
        system("cls");
        while(c<=n-1)
          {
            system("cls");
            cout<<".----------------.\n|    Sabores     |\n|----------------|\n|1.Calabresa     |\n|2.Bacon         |";
            cout<<"\n|3.Quatro Queijos|\n|4.Batata        |\n|________________|\nSabor: ";cin>>x; //Informa qual sabor
            switch(x)//Insere o sabor
              {
                case 1:y="Calabresa";sa[c].set_sabor(y);c++;break;
                case 2:y="Bacon";sa[c].set_sabor(y);c++;break;
                case 3:y="Quatro_Queijos";sa[c].set_sabor(y);c++;break;
                case 4:y="Batata";sa[c].set_sabor(y);c++;break;
                default:cout<<"Codigo invalido!";break;
              }
          }
      };
    void set_componente() //Coloca componente
      {
        int x,c=0,n=0;
        string y;
        cout<<"Quantos componentes tera a pizza: ";cin>>n;//Informa quantos componentes tera a pizza
        ca=new componentes[n];
        total_c=n;
        system("cls");
        while(c<=n-1)
          {
            system("cls");
            cout<<".----------------.\n|  Componentes   |\n|----------------|\n|1.Calabresa     |\n|2.Bacon         |";
            cout<<"\n|3.Abacate       |\n|4.Batata        |\n|________________|\nComponente: ";cin>>x; //Informa qual componente
            switch(x)//Insere o componente na pizza
              {
                case 1:y="Calabresa";ca[c].set_componente(y);c++;break;
                case 2:y="Bacon";ca[c].set_componente(y);c++;break;
                case 3:y="Abacate";ca[c].set_componente(y);c++;break;
                case 4:y="Batata";ca[c].set_componente(y);c++;break;
                default:cout<<"Codigo invalido!";break;
              }
          }
      };
    void adiciona_sabor() //Adiciona mais sabores
      {
        int x,c,n=0;
        string y;
        cout<<"Informe quantos sabores deseja adicionar: ";cin>>n; //Informa quantos sabores a mais tera a pizza
        ns=new sabor[total_s+n];
        for(c=0;c<total_s;c++)   {  set_novos_sabores(c,sa[c]); }
        total_s+=n;
        system("cls");
        while(c<=total_s-1)//Adiciona apenas o numero de sabores a mais
          {
            system("cls");
            cout<<".----------------.\n|    Sabores     |\n|----------------|\n|1.Calabresa     |\n|2.Bacon         |";
            cout<<"\n|3.Quatro Queijos|\n|4.Batata        |\n|________________|\nSabor: ";cin>>x;//Escolhe o sabor
            switch(x)//Insere o sabor
              {
                case 1:y="Calabresa";ns[c].set_sabor(y);c++;break;
                case 2:y="Bacon";ns[c].set_sabor(y);c++;break;
                case 3:y="Quatro_Queijos";ns[c].set_sabor(y);c++;break;
                case 4:y="Batata";ns[c].set_sabor(y);c++;break;
                default:cout<<"Codigo invalido!";break;
              }
          }
          sa=new sabor[total_s];
          for(c=0;c<total_s;c++)   {  set_sabores(c,ns[c]); }
          delete ns;
      };
    void adiciona_componente()//Adiciona mais componentes
      {
        int x,c,n=0;
        string y;
        cout<<"Informe quantos componentes deseja adicionar: ";cin>>n;//Informa quantos componentes a mais tera a pizza
        nc=new componentes[total_c+n];
        for(c=0;c<total_c;c++)   {  set_novos_componentes(c,ca[c]); }
        total_c+=n;
        system("cls");
        while(c<=total_c-1)//Adiciona apenas o numero de componentes a mais
          {
            system("cls");
            cout<<".----------------.\n|    Sabores     |\n|----------------|\n|1.Calabresa     |\n|2.Bacon         |";
            cout<<"\n|3.Abacate       |\n|4.Batata        |\n|________________|\nSabor: ";cin>>x; //Informa o componente
            switch(x)//Adiciona o componente a pizza
              {
                case 1:y="Calabresa";nc[c].set_componente(y);c++;break;
                case 2:y="Bacon";nc[c].set_componente(y);c++;break;
                case 3:y="Abacate";nc[c].set_componente(y);c++;break;
                case 4:y="Batata";nc[c].set_componente(y);c++;break;
                default:cout<<"Codigo invalido!";break;
              }
          }
          ca=new componentes[total_c];
          for(c=0;c<total_c;c++)   {  set_componentes(c,nc[c]); }
          delete nc;
      };
    void set_novos_sabores(int x,sabor n){ns[x]=n;}; //Função para adicionar novos sabores
    void set_sabores(int x,sabor n){sa[x]=n;};//Função para retorna os valores dos sabores adicionados
    void set_novos_componentes(int x,componentes n){nc[x]=n;};//Função para adicionar novos componentes
    void set_componentes(int x,componentes n){ca[x]=n;};//Função para retorna os valores dos componentes adicionados
		void get_pizza(int x){cout<<sa[x].get_sabor()<<ca[x].get_componente();};//Função para retorna o sabor e o componente
		string get_desc_pz(){return desc_pz;};//Função para retorna a descrição da pizza
};

class bebida //Classe bebida
{
  protected: //Declaração de variaveis
    string tipo, marca,desc_b;
    float imp,preco;
	public:
		void set_bebida() //Informa qual bebida deseja
			{
				int x;
				char s='s';
				preco=5.00;
				cout<<".----------------.\n|     Tipo     |\n|----------------|\n|1.Refrigerante|\n|2.Vinho         |";
				cout<<"\n|3.Cerevja     |\n|4.Agua          |\n|________________|\nTipo: ";cin>>x;
				while(s!='n')
					{
						switch (x)
              {
                 case 1:
                        cout<<"Digite a marca da bebida: ";cin>>marca;
                        cout<<"Digite a descricao da bebida: ";cin>>desc_b;
                        imp = 0.57;
                        s='n';
                        break;
                 case 2:
                        cout<<"Digite a marca da bebida: ";cin>>marca;
                        cout<<"Digite a descricao da bebida: ";cin>>desc_b;
                        imp = 1.00;
                        s='n';
                        break;
                 case 3:
                        cout<<"Digite a marca da bebida: ";cin>>marca;
                        cout<<"Digite a descricao da bebida: ";cin>>desc_b;
                        imp = 0.39;
                        s='n';
                        break;
                 case 4:
                        cout<<"Digite a marca da bebida: ";cin>>marca;
                        cout<<"Digite a descricao da bebida: ";cin>>desc_b;
                        imp = 0.10;
                        s='n';
                        break;
                 default: cout<<"Codigo incorreto!!\n";break;
              }
					}
			};
		string get_desc(){return desc_b;}; //Retorna a descrição da bebida
		string get_tipo(){return tipo;}; //Retorna o tipo
		string get_marca(){return marca;}; //Retorna a marca
		float get_preco(){return preco*imp;}; //Retorna o preço

};

class produto: public bebida, public pizza, public componentes //Classe do produto
{
	private: //Declaração de variaveis
		int cod,preco_base;
		float conta;
	public:
		void set_produto()//Monta o pedido
			{
				cout<<"Digite um codigo para o produto: ";cin>>cod;
				set_pizza();
				set_bebida();
				system("cls");
				cout<<"Descricao da pizza: "<<get_desc_pz()<<"\nDescricao da bebida: "<<get_desc()<<"\nMarca da bebida: "<<get_marca();
				cout<<"Tipo de bebida: "<<get_tipo();
				preco_base=20;
			};
		float calc_preco()//Calcula o preço da pizza + bebida + componentes da pizza
			{
				return conta=get_preco()+(total_c*0.05)+preco_base;
			};
		void get_produto() {cout<<get_desc_pz()<<"\n"<<get_desc();}; //Retorna a descrição do que o produto contem
};
