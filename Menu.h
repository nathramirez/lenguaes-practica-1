#include <iostream>
#include "Usuario.h"
using namespace std;

class Menu{
  public:

  bool terminar = true;
  Usuario obj;

  void estructura(){

    while(terminar == true){
      int eleccion = 0;

      cout << endl << endl << "        -BIENVENIDO A EAFIZON-      " << endl;
      cout << endl << "¿Qué tipo de usuario eres?" << endl << "1) Coordinador" << endl << "2) Cliente" << endl;
      cin >> eleccion;
    
      if(eleccion == 1){
      int eleccioncita;
        obj.coordinador(eleccioncita);
      
      } else if(eleccion == 2){
        int eleccioncita;
        obj.cliente(eleccioncita);
      }else{
          cout << endl << "La opción no está disponible" << endl;
          estructura();
        }

      string recursion = " ";
      cout << endl << "¿Desea volver al menú principal?" << endl;
      cin >> recursion;

      if(recursion == "si"){
        estructura();
      } else {
        cout << endl << endl << "     ¡HASTA PRONTO!    " << endl;
        terminar = false;
      }
    }
  };
};