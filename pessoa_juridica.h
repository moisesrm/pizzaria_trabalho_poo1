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