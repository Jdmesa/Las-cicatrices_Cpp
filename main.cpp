#include <windows.h>
#include <iostream>
#include "mapa.h"
#include "criaturaPrueba.h"


int main() {

    //solo es para que se vean los caracteres especiales en la consola (como la ñ)
    SetConsoleOutputCP(CP_UTF8);

    // Se crea un mapa de 5x5
    mapa mapa(5, 5);
    // Para obtener un nodo y ponerle un tipo.
    nodo& nodoAgua = mapa.obtenerNodo(4, 4);
    nodoAgua.setTipo("agua");
    // No creo que sea necesario explicarlo.
    criaturaPrueba* criatura = new criaturaPrueba("El dragón demoledor", 4, 4);
    nodoAgua.agregarCriatura(criatura);

    // Simulamos 5 ciclos de vida en el ecosistema (PRUEBA)
    for (int ciclo = 0; ciclo < 5; ++ciclo) {
        cout << "\n--- Ciclo " << ciclo + 1 << " ---\n";
        criatura->actuar(mapa);
        mapa.mostrarMapa();
    }

    // Limpiamos la memoria (obligatorio)
    delete criatura;
    return 0;
}