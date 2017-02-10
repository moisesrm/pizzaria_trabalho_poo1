//Libs
#include <iostream>
#include <stdlib.h>

//Classes
#include "pessoa_fisica.h"
#include "pessoa_juridica.h"
#include "pedido.h"
#include "produto.h"
#include "mesa.h"
#include "cliente.h"

using namespace std;
//Moisés Machado, Daniela Limberger, Guilherme Zaleski

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
