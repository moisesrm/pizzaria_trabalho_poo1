#include "PessoaJuridica.h"
#include "PessoaFisica.h"

class Cliente : public PessoaFisica, public PessoaJuridica{
  private: //Declaração de variaveis
	int codigo;

  public:

	Cliente(string nome, string endereco){
		this.nome = nome;
		this.endereco = endereco;
	}

	void set_cliente() //Cria um cliente
	{
		string nome_p, end_p;
		int cnpj_p, x = 0, y;
		system("cls");
		cout << "Digite o codigo: ";
		cin >> cod;
		cout << "Digite o nome: ";
		cin >> nome_p;
		cout << "Digite o endereco: ";
		cin >> end_p;
		while (x == 0)
		{
			cout << "Informe o tipo de pessoa (1.juridica/2.fisica): ";
			cin >> y; //Informa o tipo de cliente que deseja criar
			switch (y)
			{
			case 1:
				j = new pessoa_juridica; //Ponteiro para pessoa juridica é criado
				cout << "Digite o cnpj: ";
				cin >> cnpj_p;
				j->set_nome(nome_p);
				j->set_end(end_p);
				j->set_cnpj(cnpj_p);
				x = 1;
				break;
			case 2:
				f = new pessoa_fisica; //Ponteiro para pessoa fisica é criado
				f->set_nome(nome_p);
				f->set_end(end_p);
				x = 1;
				break;
			default:
				cout << "Codigo errado!!\nDigite novamente";
			}
		}
		cout << "Cadastro feito com sucesso!";
	};
	void get_cliente(int x) //Retorna os dados do cliente
	{
		system("cls");
		if (x == 1)
			cout << "Pessoa " << f->get_tipo_f() << "\nNome: " << f->get_nome_f() << "\nEndereco: " << f->get_end_f() << "\nCodigo: " << get_cod() << "\nDesconto: " << f->get_desc();
		if (x == 2)
			cout << "Pessoa " << j->get_tipo_j() << "\nNome: " << j->get_nome_j() << "\nEndereco: " << j->get_end_j() << "\nCodigo: " << get_cod() << "\nCNPJ: " << j->get_cnpj();
		cout << "\n";
		system("pause");
	};
	float desconto(float ct) //Calcula o desconto
	{
		float conta;
		conta = (ct * f->get_desc()) / 100;
		if (f->get_desc() < 5)
		{
			f->add_desc();
		}
		return conta;
	};
	void altera_cliente() //Faz a alteração dos dados do cliente
	{
		string nome_p, end_p;
		int cnpj_p, x = 0, tipo_p;
		char a;
		system("cls");
		cout << ".----------------------------.\n|Informe o que deseja alterar|\n|[N]ome                      |\n";
		cout << "|[C]odigo                    |\n|[E]ndereco                  |\n|[T]ipo                      |\n";
		cout << "|Cn[p]j                      |\n|____________________________|\n";
		cin >> a; //Informa o que deseja alterar
		cout << "Qual o tipo de pessoa (1.Juridica/2.Fisica): ";
		cin >> tipo_p; //Informa qual o tipo de pessoa o cliente é
		while (x == 0)
		{
			switch (tipo_p)
			{
			case 1:
				if (a == 'N' || a == 'n')
				{
					cout << "Escreva um novo nome: ";
					cin >> nome_p;
					j->set_nome(nome_p);
					cout << "\nConcluido";
				} //Altera nome
				if (a == 'C' || a == 'c')
				{
					cout << "Escreva um novo codigo: ";
					cin >> cod;
					cout << "\nConcluido";
				} //Altera Codigo
				if (a == 'E' || a == 'e')
				{
					cout << "Escreva um novo endereco: ";
					cin >> end_p;
					j->set_end(end_p);
					cout << "\nConcluido";
				}						  //Altera Endereço
				if (a == 'T' || a == 't') //Altera Tipo
				{
					f = new pessoa_fisica; //Cria ponteiro para pessoa fisica
					nome_p = j->get_nome_j();
					end_p = j->get_end_j(); //Passa os dados da pessoa juridica para a pessoa fisica
					j->set_nome(nome_p);
					j->set_end(end_p);
					delete j; //Deleta o ponteiro para pessoa juridica
					cout << "\nConcluido";
				}
				if (a == 'P' || a == 'p')
				{
					cout << "Escreva um novo cnpj: ";
					cin >> nome_p;
					j->set_cnpj(cnpj_p);
					cout << "\nConcluido";
				} //Altera cnpj
				x = 1;
				break;
			case 2:
				if (a == 'N' || a == 'n')
				{
					cout << "Escreva um novo nome: ";
					cin >> nome_p;
					f->set_nome(nome_p);
					cout << "\nConcluido";
				} //Altera nome
				if (a == 'C' || a == 'c')
				{
					cout << "Escreva um novo codigo: ";
					cin >> cod;
					cout << "\nConcluido";
				} //Altera codigo
				if (a == 'E' || a == 'e')
				{
					cout << "Escreva um novo endereco: ";
					cin >> end_p;
					f->set_end(end_p);
					cout << "\nConcluido";
				}						  //Altera endereço
				if (a == 'T' || a == 't') //Altera tipo
				{
					j = new pessoa_juridica; //Cria ponteiro para pessoa juridica
					cout << "Digite o cnpj: ";
					cin >> cnpj_p; //Passa os dados da pessoa fisica para a pessoa juridica
					nome_p = f->get_nome_f();
					end_p = f->get_end_f();
					j->set_nome(nome_p);
					j->set_end(end_p);
					j->set_cnpj(cnpj_p);
					delete f; //Deleta o ponteiro para pessoa fisica
					cout << "\nConcluido";
				}
				if (a == 'P' || a == 'p')
				{
					cout << "Pessoa fisica nao precisa de cnpj!";
				} //Mostra mensagem que pessoa fisica não tem cnpj
				x = 1;
				break;
			default:
				cout << "Erro no codigo!!!";
				break;
			}
		}
	};
	int get_cod() { return cod; }; //Retorna o codigo do cliente
};
