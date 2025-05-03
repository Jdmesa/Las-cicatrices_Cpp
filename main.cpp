#include <windows.h>
#include <iostream>
#include "mapa.h"
#include "criaturaPrueba.h"
#include "ecosistema.h"


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
    if (opcion == '1') {
        ecosistema valle(5,5,'b',10);
    } else {
        ecosistema valle(5,5,'v',10);
    }

    return 0;
}
