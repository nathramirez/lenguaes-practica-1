#include <iostream>
#include "Nodo.h"
using namespace std;


class Inventario{
  public:
    Nodo* cabeza;


    void agregarArt(string n, float p, int idd, int cant, string tip){
      Nodo* temporal = cabeza;
      Nodo* nd = new Nodo(n,p,idd,cant,tip);
  
      if(cabeza == NULL){
        cabeza = nd;
      } else if(cabeza->siguiente == NULL){
        cabeza->siguiente = nd;
      } else{
          while(temporal->siguiente){
            temporal = temporal->siguiente;
            } 
          temporal->siguiente = nd;
      }
    };



    void modificarArt(){
      Nodo* temporal = cabeza;

      imprimirLista();
      int idModificar;
      cout << endl << "Ingresa el id del artículo que quieres modificar" << endl;
      cin >> idModificar;
      int eleccion;
      
      if(recorrerLista(idModificar) == true){
        cout << endl << "¿Cuál atributo quieres cambiar?" << endl << "1) Nombre" << endl << "2) Precio" << endl << "3) Cantidad" << endl;
        cin >> eleccion;

        switch(eleccion){
          case 1:{
              string name = " ";
              cout << endl << "¿Ingrese el nuevo nombre" << endl;
              cin >> name;
            
              while(temporal){
                if(idModificar == temporal->articulo->id){
                  temporal->articulo->nombre = name;
                  break;
                }
                temporal = temporal->siguiente;
              }
              break;
          }
          case 2:{
              float price;
              cout << endl << "Ingrese el nuevo precio" << endl;
              cin >> price;

              while(temporal){
                if(idModificar == temporal->articulo->id){
                  temporal->articulo->precio = price;
                  break;
                }
                temporal = temporal->siguiente;
              }
              break;
          }
          case 3:{
            int amount;
            cout << endl << "Ingrese la nueva cantidad" << endl;
            cin >> amount;

            while(temporal){
                if(idModificar == temporal->articulo->id){
                  temporal->articulo->cantidad = amount;
                  break;
                }
                temporal = temporal->siguiente;
              }
              break;
          }
        }
      }
      string recursion = " ";
      imprimirLista();
      cout << endl << "¿Desea modificar otro artículo?" << endl;
      cin >> recursion;
      if(recursion == "si"){
        modificarArt();
      }
    };



    void eliminarNodo(){
      Nodo* temporal = cabeza;
      Nodo* temporalDos;
      
      if(temporal == NULL){
        cout << "La lista está vacía" << endl;
        return;
      }

      imprimirLista();
      
      int idEliminar;
      cout << endl << "Ingresa el id del artículo que quieres eliminar" << endl;
      cin >> idEliminar;

      if(temporal->articulo->id != idEliminar){
        
        if(recorrerLista(idEliminar) == true){
          
          while(temporal->siguiente){
            
            if(temporal->siguiente->articulo->id == idEliminar){
              if(temporal->siguiente->siguiente){
                temporalDos = temporal->siguiente;
                temporal->siguiente = temporal->siguiente->siguiente;
                delete temporalDos;
                break;
                
              }else{
                temporalDos = temporal->siguiente->siguiente;
                temporal->siguiente = NULL;
                delete temporalDos;
                break;
              }
            }
            temporal = temporal->siguiente;
          }
        } 
      } else{
          cabeza = cabeza->siguiente;
          delete temporal; 
        }
        
      imprimirLista();
      
      string recursion = " ";
      cout << endl << "¿Desea eliminar otro artículo?" << endl;
      cin >> recursion;
      if(recursion == "si"){
        eliminarNodo();
      }
    };



    void imprimirLista(){
      Nodo* temporal = cabeza;
      if(cabeza == NULL){
        cout << endl << "La lista está vacía" << endl;
      }else {
        while(temporal){
          cout << temporal->articulo->nombre <<" $"<< temporal->articulo->precio <<" "<< temporal->articulo->id <<" "<< temporal->articulo->cantidad <<" "<< temporal->articulo->tipo << endl;
            temporal = temporal->siguiente;
        }
      }
    };


  
    bool recorrerLista(int iid){
      Nodo* temporal = cabeza;
      bool sw = false;

      while(temporal){
        if(iid == temporal->articulo->id){
          sw = true;
          break;
        }
        temporal = temporal->siguiente;
      }
      if(sw == false){
        cout << "El id no existe en el sistema" << endl << endl;
      }
      return (sw);
    };



    NodoCarrito* head;
    void carrito(){
      NodoCarrito* aux;
      Nodo* temporal = cabeza;
      
      string name = " ";
          cout << endl << "Ingrese el nombre del producto" << endl;
          cin >> name;

      if(temporal == NULL){
        cout << endl << "El inventario está vacío" << endl;
      }
      
      bool swuno = false;
      while(temporal){
        if(temporal->articulo->nombre == name){
          swuno = true;
          break;
        }
        temporal = temporal->siguiente;
      }
      if(swuno == false){
        cout << endl << "Este producto no existe en el sistema" << endl;
      }
      
      temporal = cabeza;
      
      while(temporal){
        if(swuno == true){
          if(temporal->articulo->nombre == name){
            if(head == NULL){
              NodoCarrito* nddos = new NodoCarrito(temporal->articulo->nombre, temporal->articulo->precio, 1);
              head = nddos;
              temporal->articulo->cantidad -= 1;
              
              bool sw = true;
              while(sw == true){
                string descuento = " ";
                cout << endl << "¿Desea añadir uno más?" << endl;
                cin >> descuento;
                
                if(descuento == "si"){
                  if(temporal->articulo->cantidad != 0){
                    temporal->articulo->cantidad -= 1;
                    head->objcarrito->cantidad += 1;
                  } else{
                    cout << "Ya no hay más "<< name << " disponibles" << endl;
                    sw = false;
                  }
                } else{
                  sw = false;
                  break;
                }
              }

            } else{
                aux = head;
                while(aux->siguiente){
                  aux = aux->siguiente;
                }
                NodoCarrito* nddos = new NodoCarrito(temporal->articulo->nombre, temporal->articulo->precio, 1);
                aux->siguiente = nddos;
                temporal->articulo->cantidad -= 1;
              
                bool sw = true;
                while(sw == true){
                  string descuento = " ";
                  cout << endl << "¿Desea añadir uno más?" << endl;
                  cin >> descuento;
                  
                  if(descuento == "si"){
                    if(temporal->articulo->cantidad != 0){
                      temporal->articulo->cantidad -= 1;
                      aux->siguiente->objcarrito->cantidad += 1;
                    } else{
                      cout << "Ya no hay más "<< name << " disponibles" << endl;
                      sw = false;
                    }  
                  } else{
                    sw = false;
                    break;
                  }
                }
            }
          } 
        } 
        temporal = temporal->siguiente;
      }
      string recursion = " ";
      cout << endl << "¿Quieres agregar otro artículo?" << endl;
      cin >> recursion;
      if(recursion == "si"){
        carrito();
      } else{
        imprimirCarrito();
      }
    };



    void imprimirCarrito(){
      NodoCarrito* aux = head;

      if(head == NULL){
        cout << endl << "La lista está vacía" << endl;
      } else {
          while(aux){
          cout << aux->objcarrito->nombre <<" "<< aux->objcarrito->cantidad << endl;
          aux = aux->siguiente;
        }
      }
    };



    void imprimirTipo(){
      Nodo* temporal = cabeza;

      cout << endl << "Artículos deportivos: " << endl;
      while(temporal){
        if(temporal->articulo->tipo == "deporte"){
          cout << temporal->articulo->nombre <<" $"<< temporal->articulo->precio <<" "<< temporal->articulo->cantidad <<" "<< endl;
        }
        temporal = temporal->siguiente;
      }
      
      temporal = cabeza;

      cout << endl << "Artículos tecnológicos: " << endl;
      while(temporal){
        if(temporal->articulo->tipo == "tecnologia"){
          cout << temporal->articulo->nombre <<" $"<< temporal->articulo->precio <<" "<< temporal->articulo->cantidad <<" "<< endl;
        }
        temporal = temporal->siguiente;
      }

      temporal = cabeza;

      cout << endl << "Artículos extranjeros: " << endl;
      while(temporal){
        if(temporal->articulo->tipo == "extranjero"){
          cout << temporal->articulo->nombre <<" $"<< temporal->articulo->precio <<" "<< temporal->articulo->cantidad <<" "<< endl;
        }
        temporal = temporal->siguiente;
      }
      
      temporal = cabeza;
      if(temporal == NULL){
        cout << endl << "El inventario está vacío" << endl;
      }
    };



  void pagarCarrito(){
    NodoCarrito* aux = head;
    Nodo* temporal = cabeza;
    double pago = 0;
    float descuento = 0.10;
    bool pago_descuento = false;

    if(head->siguiente == NULL){
      pago += head->objcarrito->precio;
    } else{
      while(aux){
        if(aux->siguiente){
        if(aux->objcarrito->nombre == aux->siguiente->objcarrito->nombre){
          pago += aux->objcarrito->precio * aux->objcarrito->cantidad;
          pago_descuento = true;
          aux = aux->siguiente;
          }else{
            pago += aux->objcarrito->precio * aux->objcarrito->cantidad;
            aux = aux->siguiente;
            } 
          } else{
              pago += aux->objcarrito->precio * aux->objcarrito->cantidad;
              aux = aux->siguiente;
          }
      /*if(aux->siguiente == NULL){
        break;
      }*/
      }
    }

    imprimirCarrito();
    cout << endl << "Total: " << pago << endl;
    if(pago_descuento == true){
      pago -= pago * descuento;
      cout << endl << "Total con descuento: "<< pago << endl;
    }

    aux = head;
    int decision;
      if(head == NULL){
        cout << endl << "El carrito está vacío" << endl;
        return;
      } else{
          cout << endl << "1) Pagar" << endl << "2) Cancelar" << endl;
          cin >> decision;
        }
  
    if (decision == 1){
      cout << endl << "Pago exitoso :)" << endl;
      
      NodoCarrito* auxDos;
      while(aux){
        if(aux->siguiente == NULL){
          delete aux;
          break;
        } else{
            auxDos = aux;
            aux = aux->siguiente;
            delete auxDos;
          }
        }
      head = NULL;
    }

    if (decision == 2){
      cout << endl << "Compra cancelada :(" << endl;

      NodoCarrito* auxDos;
      while(aux){
        while(temporal){
          if(temporal->articulo->nombre == aux->objcarrito->nombre){
              temporal->articulo->cantidad += aux->objcarrito->cantidad;
              break;
            }
          temporal = temporal->siguiente;
        }
        aux = aux->siguiente;
      }
      
      while(aux){
        auxDos = aux;
        aux = aux->siguiente;
        delete auxDos;
      }
      head = NULL;
    }
    imprimirLista();
    cout << endl << length << endl;
  };



  int length;
  void tamañoCarrito(){
    NodoCarrito* aux = head;
    
    while(aux){
      length ++;
      aux = aux->siguiente;
    }
  };
};