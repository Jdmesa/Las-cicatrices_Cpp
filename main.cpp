#include <windows.h>
#include <iostream>
#include <limits>
#include "Ecosistema/ecosistema.h"

using namespace std;

int main() {
    srand(time(0)); // Aleatoriedad cada vez que se ejecuta el programa.

    //solo es para que se vean los caracteres especiales en la consola (como la ñ)
    SetConsoleOutputCP(CP_UTF8);

    char opcion;
    cout << "Selecciona el bioma: " << endl;
    cout << "1. Boscoso - Terrenos Densos, Claros y Oscuros" << endl;
    cout << "2. Volcanico - Terrenos Rocosos, Senizas y Fumarolas" << endl;
    cout << "Ingresa la opcion: ";

    cin>>opcion;
    int cantidadCiclos, numeroAleatorio, tamanioMapa;
    char bioma;
    cout << "Ingresa la cantidad de ciclos";
    if (opcion == '1') {
        // Genera un número aleatorio entre 0 y 10 (15 - 5)
        numeroAleatorio = rand() % 11;
        // Desplaza el rango para que esté entre 5 y 15
        tamanioMapa = numeroAleatorio + 5;
        bioma = 'b';
    } else if (opcion == '2') {
        numeroAleatorio = rand() % 11;
        tamanioMapa = numeroAleatorio + 5;
        bioma = 'v';
    }

    ecosistema valle(tamanioMapa,tamanioMapa,bioma,10);
    /*
     *TODO:
     * - Realizar seleccion de ciclos aleatorio
    */
    return 0;
}
