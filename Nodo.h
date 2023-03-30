#include <iostream>
#include "articulos.h"
using namespace std;


class Nodo{
public:
  Articulos* articulo;
  Nodo* siguiente;

  Nodo(string n, float p, int idd, int cant, string tip){
    articulo = new Articulos(n,p,idd,cant,tip);
    
  };
};

class ObjetoCarrito{
public:
  string nombre = " ";
  float precio;
  int cantidad;

  ObjetoCarrito(string name, float price, int amount){
    nombre = name;
    precio = price;
    cantidad = amount;
  };
};



class NodoCarrito{
public:
  ObjetoCarrito* objcarrito;
  NodoCarrito* siguiente;

  NodoCarrito(string name, float price, int amount){
    objcarrito = new ObjetoCarrito(name,price,amount);
  };
};