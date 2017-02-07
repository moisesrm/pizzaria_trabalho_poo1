#include <iostream>
#include <stdlib.h>
using namespace std;
//Moisés Machado, Daniela Limberger, Guilherme Zaleski

class pessoa_fisica  //Classe de Pesseoa Fisica
{
	private: //Declaração de variaveis
    string tipo,nome,end;
    float desc;
  public:
    pessoa_fisica() //Construtor da classe para iniciar os parametros
      {
        tipo = "fisica";
        nome = "";
        end = "";
        desc = 0.25;
      };
    void set_nome(string nome_p) { nome = nome_p; }; //Insere o nome para a classe
    void set_end(string end_p)   { end = end_p;   };//Insere o endereço para a classe
		void add_desc (){desc+=0.25;}; //Faz a soma do desconto
		string get_tipo_f() { return tipo;}; //Retorna o tipo de pessoa
		string get_nome_f() { return nome;};//Retorna o nome
		string get_end_f() { return end;};//Retorna o endereço
		float get_desc() { return desc;};//Retorna o desconto total
};

class pessoa_juridica //Classe de Pessoa Juridica
{
	private: //Declaração de variaveis
    string tipo,nome,end;
    int cnpj;
  public:
    pessoa_juridica() //Construtor da classe para iniciar os parametros
      {
        tipo = "juridica";
        nome = "";
        end = "";
        cnpj = 0;
      };
    void set_nome(string nome_p) { nome = nome_p; };//Insere o nome para a classe
    void set_end(string end_p)   { end = end_p;   };//Insere o endereço para a classe
    void set_cnpj(int cnpj_p)    { cnpj = cnpj_p; };//Insere o cnpj para a classe
		string get_tipo_j() { return tipo;}; //Retorna o tipo de pessoa
		string get_nome_j() { return nome;}; //Retorna o nome de pessoa
		string get_end_j() { return end;}; //Retorna o endereço de pessoa
		int get_cnpj() { return cnpj;}; //Retorna o cnpj de pessoa
};

class cliente //Classe Cliente
{
	private: //Declaração de variaveis
		pessoa_fisica *f;
		pessoa_juridica *j;
		int cod;
	public:
		void set_cliente() //Cria um cliente
			{
				string nome_p,end_p;
				int cnpj_p,x=0,y;
				system("cls");
				cout<<"Digite o codigo: ";cin>>cod; cout<<"Digite o nome: ";cin>>nome_p;	cout<<"Digite o endereco: ";cin>>end_p;
				while(x==0)
				{
					cout<<"Informe o tipo de pessoa (1.juridica/2.fisica): ";cin>>y; //Informa o tipo de cliente que deseja criar
					switch (y)
					{
						case 1:
								j=new pessoa_juridica; //Ponteiro para pessoa juridica é criado
								cout<<"Digite o cnpj: ";cin>>cnpj_p;
								j->set_nome(nome_p);j->set_end(end_p);j->set_cnpj(cnpj_p);
								x=1;break;
						case 2:
								f=new pessoa_fisica; //Ponteiro para pessoa fisica é criado
								f->set_nome(nome_p);f->set_end(end_p);
								x=1;break;
						default: cout<<"Codigo errado!!\nDigite novamente";
					}
				}
				cout<<"Cadastro feito com sucesso!";
			};
		void get_cliente(int x) //Retorna os dados do cliente
			{
				system("cls");
				if (x==1)
					cout<<"Pessoa "<<f->get_tipo_f()<<"\nNome: "<<f->get_nome_f()<<"\nEndereco: "<<f->get_end_f()<<"\nCodigo: "<<get_cod()<<"\nDesconto: "<<f->get_desc();
				if (x==2)
					cout<<"Pessoa "<<j->get_tipo_j()<<"\nNome: "<<j->get_nome_j()<<"\nEndereco: "<<j->get_end_j()<<"\nCodigo: "<<get_cod()<<"\nCNPJ: "<<j->get_cnpj();
				cout<<"\n";system("pause");
			};
		float desconto (float ct) //Calcula o desconto
      {
        float conta;
        conta=(ct*f->get_desc())/100;
        if(f->get_desc()<5)    { f->add_desc(); }
        return conta;
      };
    void altera_cliente() //Faz a alteração dos dados do cliente
      {
        string nome_p,end_p;
				int cnpj_p,x=0,tipo_p;
        char a;
        system("cls");
        cout<<".----------------------------.\n|Informe o que deseja alterar|\n|[N]ome                      |\n";
        cout<<"|[C]odigo                    |\n|[E]ndereco                  |\n|[T]ipo                      |\n";
        cout<<"|Cn[p]j                      |\n|____________________________|\n";cin>>a;//Informa o que deseja alterar
        cout<<"Qual o tipo de pessoa (1.Juridica/2.Fisica): ";cin>>tipo_p;//Informa qual o tipo de pessoa o cliente é
        while(x==0)
					{
						switch (tipo_p)
						{
							case 1:
								if (a=='N' || a=='n') {cout<<"Escreva um novo nome: ";cin>>nome_p;j->set_nome(nome_p);cout<<"\nConcluido";} //Altera nome
								if (a=='C' || a=='c') {cout<<"Escreva um novo codigo: ";cin>>cod;cout<<"\nConcluido";} //Altera Codigo
								if (a=='E' || a=='e') {cout<<"Escreva um novo endereco: ";cin>>end_p;j->set_end(end_p);cout<<"\nConcluido";}//Altera Endereço
								if (a=='T' || a=='t') //Altera Tipo
									{
										f=new pessoa_fisica; //Cria ponteiro para pessoa fisica
										nome_p=j->get_nome_j();end_p=j->get_end_j();//Passa os dados da pessoa juridica para a pessoa fisica
										j->set_nome(nome_p);j->set_end(end_p);
										delete j; //Deleta o ponteiro para pessoa juridica
										cout<<"\nConcluido";
									}
								if (a=='P' || a=='p') {cout<<"Escreva um novo cnpj: ";cin>>nome_p;j->set_cnpj(cnpj_p);cout<<"\nConcluido";}//Altera cnpj
								x=1;break;
							case 2:
									if (a=='N' || a=='n') {cout<<"Escreva um novo nome: ";cin>>nome_p;f->set_nome(nome_p);cout<<"\nConcluido";}//Altera nome
									if (a=='C' || a=='c') {cout<<"Escreva um novo codigo: ";cin>>cod;cout<<"\nConcluido";}//Altera codigo
									if (a=='E' || a=='e') {cout<<"Escreva um novo endereco: ";cin>>end_p;f->set_end(end_p);cout<<"\nConcluido";}//Altera endereço
									if (a=='T' || a=='t')//Altera tipo
										{
											j=new pessoa_juridica; //Cria ponteiro para pessoa juridica
											cout<<"Digite o cnpj: ";cin>>cnpj_p;//Passa os dados da pessoa fisica para a pessoa juridica
											nome_p=f->get_nome_f();end_p=f->get_end_f();
											j->set_nome(nome_p);j->set_end(end_p);j->set_cnpj(cnpj_p);
											delete f; //Deleta o ponteiro para pessoa fisica
											cout<<"\nConcluido";
										}
									if (a=='P' || a=='p') {cout<<"Pessoa fisica nao precisa de cnpj!";} //Mostra mensagem que pessoa fisica não tem cnpj
									x=1;break;
							default:cout<<"Erro no codigo!!!";break;
						}
					}
      };
    int get_cod() { return cod;}; //Retorna o codigo do cliente
};

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
	private://Declaração de variaveis
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

class pedidos//Classe dos pedidos
{
  private://Declaração de variaveis
		int num_m,cod_cli,total_produto;
		produto *p,*np;
		float pedido_fim,ac,desconto,bruto;
  public:
		void set_mesa_cli(int n,int c) //Diz o numero e codigo do cliente
			{
				num_m=n;
				cod_cli=c;
			};
		void inclui_produto() //Adiciona mais um produto
			{
				int x;
				cout<<"Digite o numero de produtos: ";cin>>total_produto;
				p=new produto[total_produto];
				for(x=0;x<total_produto;x++)
					{
						cout<<"Produto numero "<<x+1<<" ";
						p[x].set_produto();
						system("cls");
					}
			};
		void exclui_produto() //Exclui algum produto
			{
				int x,y;
				cout<<"Digite o numero do produtos que deseja excluir: ";cin>>y;
				np=new produto[total_produto-1];
				for(x=0;x<total_produto;x++)
					{
						if(x!=y-1)
							{set_inclui_novo(x,p[x]);}
					}
				delete p;
				total_produto-=1;
				p=new produto [total_produto];
				for(x=0;x<total_produto;x++)
					{
						if(x == y)
						set_inclui_novo(x,p[x]);

					}
			};
		void set_inclui_novo(int x, produto p){np[x]=p;}; //Passa os parametros para os um novo vetor
		void cupom (cliente c) //Faz o cupom fiscal
			{
				int t,m;
				cout<<"O informe o tipo de cliente (1.Fisica/2.Juridica): ";cin>>t;
				cout<<"Informe o tipo de mesa (1.Normal/2.Especial): ";cin>>m;
				c.get_cliente(t);
				p->get_produto();
				calc_pedido(m,t,c);
				cout<<"\nValor bruto: R$"<<bruto<<"\nValor liquido: R$"<<pedido_fim<<"\nDesconto: R$"<<desconto;
				if(t==2)
					{cout<<"\nAcrecimo: "<<ac;}
				cout<<"\n";system("pause");
			};
		void calc_pedido(int mesa,int d ,cliente c) //Calcula o valor bruto e valor liquido
			{
				int x;
				float a,b;
				pedido_fim=0;
				for(x=0;x<total_produto;x++)
					{ pedido_fim+=p->calc_preco();}
				bruto=pedido_fim;
				if(mesa == 2)
					{
						if(d == 1)
							{
								b=(pedido_fim*2)/100;
								pedido_fim+=b;
								ac=(pedido_fim*2)/100;
								a=c.desconto(pedido_fim);
								desconto=c.desconto(pedido_fim);
								pedido_fim-=a;
							}
						else
							{
								pedido_fim=(pedido_fim*2)/100;
								ac=(pedido_fim*2)/100;
							}
					}
				if(mesa == 1)
					{
						if(d == 1)
							{
								c.desconto(pedido_fim);
								desconto=c.desconto(pedido_fim);
								pedido_fim-=a;
							}
					}
			};
};

int main ()
{
	int num_c,num_m,x=1,a,b,d,e,cont_c=0,cont_m=0,cont_p=0;
	cliente *c;
	mesa *m;
  pedidos *p;
	cout<<"Informe o numero de clientes: "; cin>>num_c;
	cout<<"Informe o numero de mesas: "; cin>>num_m;
	c = new cliente [num_c];
	m = new mesa [num_m];
	p = new pedidos [num_m];
	while(x!=0)
	{
		system("cls");
		cout<<"Bem-vindo ao I Love Abacate!\n";
		cout<<"1.Cliente\n2.Mesa\n3.Pedido\n4.Sair\n";cin>>x;
		switch(x)
			{
				case 1:
								system("cls");
								cout<<"1.Cria cliente\n2.Dados\n3.Altera dados\n4.Codigo do cliente\n5.Sair\n";cin>>a;
								switch(a)
									{
										case 1:
													 if(cont_c<num_c)
														{
														 c[cont_c].set_cliente();
														 cont_c++;break;
														}
													 else
														{
															cout<<"Lista de clientes cheia";break;
														}
										case 2:
													 cout<<"Digite o numero do cliente e o tipo (1.Fisico/2.Juridico): ";cin>>b>>d;
													 c[b-1].get_cliente(d);break;
										case 3:
													 cout<<"Digite o numero do cliente: ";cin>>b;
													 c[b-1].altera_cliente();break;
										case 4:
													 cout<<"Digite o numero do cliente: ";cin>>b;
													 cout<<"Codigo do cliente: "<<c[b-1].get_cod();system("pause");break;
										case 5:
														break;
										default: cout<<"Codigo incorreto";break;
									}
								break;
				case 2:
								system("cls");
								cout<<"1.Inserir mesa\n2.Descricao da mesa\n3.Reserva\n4.Tipo da mesa\n5.Sair\n";cin>>a;
								switch(a)
									{
										case 1:
													 if(cont_m<num_m)
														{
														 m[cont_m].set_mesa();
														 cont_m++;break;
														}
													 else
														{
															cout<<"Lista de mesas cheia";break;
														}
										case 2:
													 cout<<"Digite o numero da mesa: ";cin>>b;
													 m[b-1].get_mesa();break;
										case 3:
													 cout<<"Digite o numero da mesa: ";cin>>b;
													 m[b-1].set_disp();break;
										case 4:
													 cout<<"Digite o numero da mesa: ";cin>>b;
													 cout<<"Tipo da mesa: "<<m[b-1].get_tipo();system("pause");break;
										case 5:
														break;
										default: cout<<"Codigo incorreto";break;
									}
								break;
				case 3:
								system("cls");
								cout<<"1.Mesa/Cliente\n2.Inclui Produto\n3.Exclui Produto\n4.Tipo da mesa\n5.Sair\n";cin>>a;
								switch(a)
									{
										case 1:
													 if(cont_p<num_m)
														{
															cout<<"Indique o numero e a mesa do cliente:"; cin>>b>>d;
															e=c[b].get_cod();
															p[cont_p].set_mesa_cli(d,e);
															cont_p++;break;
														}
													 else
														{
															cout<<"Lista de pedidos cheia";break;
														}
										case 2:
													 cout<<"Digite o numero do pedido: ";cin>>b;
													 p[b-1].inclui_produto();break;
										case 3:
													 cout<<"Digite o numero do pedido: ";cin>>b;
													 p[b-1].exclui_produto();break;
										case 4:
													 cout<<"Digite o numero do pedido e o numero do cliente: ";cin>>b>>d;
													 p[b-1].cupom(c[d-1]);break;
										case 5:
														break;
										default: cout<<"Codigo incorreto";break;
									}
								break;
				case 4:
							 x=0;break;
			}
	}
	return 0;
}
