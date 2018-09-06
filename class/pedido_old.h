
class pedidos//Classe dos pedidos
{
  private: //Declaração de variaveis
		int num_m,cod_cli,total_produto;
		produto *p,*np;
		float pedido_fim,ac,desconto,bruto;
  public:


    // //Calcula o preço da pizza + bebida + componentes da pizza
    // float calculaPreco(){
    //   //TOTAL de COMPONENTES ADICIONADOS * 0.05
    //   //this->get_preco() = BEBIDA
	// 		float conta = this->get_preco() + (total_c*0.05) + this->PRECO_BASE;
    //   return conta;
    // }


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