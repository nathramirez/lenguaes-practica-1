#include <iostream>
#include "sistema.h"

using namespace std;

class Usuario{
public:

  void coordinador(int eleccioncita){
      cout << endl << "¿Qué acción quieres hacer?" << endl << "1) Agregar artículo" << endl << "2) Modificar artículo" << endl << "3) Eliminar artículo" << endl;
      cin >> eleccioncita;
    
      switch(eleccioncita){
        case 1:
            coordinadorUno();
            break;
        case 2: 
            Sistema::inventario.modificarArt();
            break;
        case 3:
            Sistema::inventario.eliminarNodo();
            break;
      }
    };



  void cliente(int eleccioncita){
      cout << endl << "¿Qué acción quieres hacer?" << endl << "1) Mirar el inventario"  << endl << "2) Agregar al carrito" << endl << "3) Mirar el carrito" << endl << "4) Pagar el carrito" << endl;
      cin >> eleccioncita;

      switch(eleccioncita){
        case 1:
            Sistema::inventario.imprimirTipo(); 
            break;
        case 2:
            Sistema::inventario.carrito();
            break;
        case 3:
            Sistema::inventario.imprimirCarrito();
            break;
        case 4:
            Sistema::inventario.pagarCarrito();
            break;
          
      } 
    };



  void coordinadorUno(){
    string n = " ";
    float p;
    int idd;
    int cant;
    string tip = " ";
        
    cout << "Ingresa el nombre" << endl;
    cin >> n;
    cout << "Ingresa el precio" << endl;
    cin >> p;
    cout << "Ingresa el id" << endl;
    cin >> idd;
    cout << "Ingresa la cantidad" << endl;
    cin >> cant;
    cout << "Ingresa el tipo" << endl;
    cin >> tip;
        
    Sistema::inventario.agregarArt(n,p,idd,cant,tip);

    string choice = " ";
    cout << endl << "¿Deseas agregar otro artículo?" << endl;
    cin >> choice;
    if(choice=="si"){
        coordinadorUno();
    } else{
      Sistema::inventario.imprimirLista();
    }
  };
};