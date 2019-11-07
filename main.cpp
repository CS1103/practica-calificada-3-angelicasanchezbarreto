#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include "funciones.cpp"
#include "set"

using namespace std;

int main() {

    list<string> productos;
    map<string,int> aliasimpor;

    leer(productos,aliasimpor);

    

    //CREAR UN NUEVO ARCHIVO
    //ofstream archivo_salida("resultado.txt");    // Se abre el archivo para escribir.
    /*
    cin.getline(persona.name, 80);              // Se almacena en la variable
    archivo_salida << persona.name << endl;     // Se escribe en el archivo
    archivo_salida.close();    // SE cierra el archivo

     */

    return 0;
}