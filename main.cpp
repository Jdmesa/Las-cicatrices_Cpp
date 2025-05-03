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
    if (opcion == '1') {
        ecosistema valle(5,5,'b',10);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else {
        ecosistema valle(5,5,'v',10);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}
