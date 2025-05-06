#include <windows.h>
#include <iostream>
#include <limits>
#include "Ecosistema/ecosistema.h"

using namespace std;

int main() {
    srand(time(0)); // Aleatoriedad cada vez que se ejecuta el programa.

    // Solo es para que se vean los caracteres especiales en la consola (como la ñ)
    SetConsoleOutputCP(CP_UTF8);

    char opcion;
    cout << "Selecciona el bioma: " << endl;
    cout << "1. Boscoso - Terrenos Densos, Claros y Oscuros" << endl;
    cout << "2. Volcanico - Terrenos Rocosos, Senizas y Fumarolas" << endl;
    cout << "Ingresa la opcion: ";
    cin >> opcion;

    int cantidadCiclos, numeroAleatorio, tamanioMapa;
    char bioma;

    if (opcion == '1') {
        numeroAleatorio = rand() % 11; // 0 a 10
        tamanioMapa = numeroAleatorio + 5; // 5 a 15
        bioma = 'b';
    } else if (opcion == '2') {
        numeroAleatorio = rand() % 11; // 0 a 10
        tamanioMapa = numeroAleatorio + 5; // 5 a 15
        bioma = 'v';
    } else {
        cout << "Opción no válida." << endl;
        return 1;
    }


    numeroAleatorio = rand() % 21; // 0 a 20
    cantidadCiclos = numeroAleatorio + 10; // 10 a 30

    cout << "Tamaño del mapa generado: " << tamanioMapa << "x" << tamanioMapa << endl;
    cout << "Cantidad de ciclos generada: " << cantidadCiclos << endl;

    ecosistema valle(tamanioMapa, tamanioMapa, bioma, cantidadCiclos);

    return 0;
}

