#include <string>

class Componente{
  protected:
    string nome;

  public:
    Componente(){
      nome = ""; 
    };

    void setNome(string nome){
      this.nome = nome;
    };

    string getNome(){
      return nome; 
    };
};