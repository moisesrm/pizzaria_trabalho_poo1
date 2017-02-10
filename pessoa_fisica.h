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