#include "Menu.h"
#include <iostream>
using namespace std;


int main(){
  Sistema::inventario.agregarArt("pc", 6543, 12, 4, "tecnologia");
  Sistema::inventario.agregarArt("raqueta", 4533, 123, 6, "deporte");
  Sistema::inventario.agregarArt("mouse", 545, 1234, 7, "tecnologia");
  Sistema::inventario.agregarArt("balon", 545, 12345, 7, "deporte");
  Sistema::inventario.agregarArt("chicles", 200, 123456, 7, "extranjero");
  Sistema::inventario.agregarArt("ropa", 300, 123457, 7, "extranjero");
  
  Menu obj;
  obj.estructura();
}