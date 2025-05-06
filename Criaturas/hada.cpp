//
// Created by Julian on 3/05/2025.
//
#include <cstdlib>
#include <ctime>
#include "hada.h"
#include <random>
#include <algorithm> // Para min y max

hada::hada(const string &nombre, int fila, int columna) : nombre(nombre), criatura(fila, columna, 3) {
}

void hada::moverse(mapa &m) {

    int nuevaFila = fila + (rand() % 3 - 1);
    int nuevaCol = columna + (rand() % 3 - 1);

    // Limitar dentro del mapa
    nuevaFila = std::max(0, std::min(nuevaFila, m.getFilas() - 1));
    nuevaCol = std::max(0, std::min(nuevaCol, m.getColumnas() - 1));

    // No moverse si no cambia de posición
    if (nuevaFila == fila && nuevaCol == columna) return;

    // Actualizar posición en el mapa
    m.obtenerNodo(fila, columna).eliminarCriatura(this);
    m.obtenerNodo(nuevaFila, nuevaCol).agregarCriatura(this);

    // Mostrar información del movimiento
    std::cout << nombre << " (Hada)-> Se movió de Fila: " << fila + 1 << " Columna: " << columna + 1;
    std::cout << " a Fila: " << nuevaFila + 1 << " Columna: " << nuevaCol + 1;
    std::cout << " | Bioma actual: " << m.obtenerNodo(nuevaFila, nuevaCol).getTipo() << std::endl;

    // Actualizar la posición interna
    setPosicion(nuevaFila, nuevaCol);
}

void hada::evolucion(mapa &m){
    int numeroAdivinador = 5;
    random_device rd2;
    mt19937 gen2(rd2());
    uniform_int_distribution<> distribucionRango(0, 6); // Rango de 0 a 6

    int numeroEnRangoRandom = distribucionRango(gen2);
    if (numeroEnRangoRandom == numeroAdivinador) {
        if (cicloEv == "zombie") {
            morir(m);
        } else {
            random_device rd3;
            mt19937 gen3(rd3());
            uniform_int_distribution<> distribucionOpciones(0, 2);
            vector<string> opciones2 = { "adulto", "evolutivo", "zombie" };
            int indice = distribucionOpciones(gen3);
            string opcion = opciones2[indice];
            setCiclo(opcion);

            cout << "El Hada " << nombre << " evolucionó a " << opcion << endl;
        }
    }
}


void hada::setPosicion(int f, int c) {
    fila = f;
    columna = c;
}

string hada::getNombre() const {
    return nombre;
}

int hada::getFila() const {
    return fila;
}

int hada::getColumna() const {
    return columna;
}
