#include <iostream>
using namespace std;


class Articulos{
public:

  string nombre;
  float precio;
  int id;
  int cantidad;
  string tipo;
  double impuesto = 0.10;

  Articulos(string n, float p, int idd, int cant, string tip){
    nombre = n;
    tipo = tip;
    if(tipo == "extranjero"){
      precio = p;
      precio += precio * impuesto;
    } else{
      precio = p;
    }
    id = idd;
    cantidad = cant;
    tipo = tip;
  };


  void precio_extranjero(){
    
  };
};


class Tecnologia: public Articulos{
  
};


class Deportes: public Articulos{

};


/*class Extranjero: public Articulos{
  public:
    float impuesto = 0.10; 
    float this->precio = impuesto * this->precio;

    Extranjero(){
    
  };
};*/