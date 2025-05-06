 //
// Created by Julian on 3/05/2025.
//
#include "enano.h"
#include <iostream>
#include <random>
#include <algorithm> // Para min y max
using namespace std;

enano::enano(string nombre, int fila, int columna) : nombre(nombre), criatura(fila, columna, 2) {}

void enano::moverse(mapa &m) {
    // Movimiento aleatorio a nodo vecino
    int nuevaFila = fila + (rand() % 3 - 1);     // -1, 0, 1
    int nuevaCol = columna + (rand() % 3 - 1);   // -1, 0, 1

    // Limitar dentro del mapa
    nuevaFila = max(0, min(nuevaFila, m.getFilas() - 1));
    nuevaCol = max(0, min(nuevaCol, m.getColumnas() - 1));

    if (nuevaFila == fila && nuevaCol == columna) return;  // No se mueve si es la misma posición generada

    // Se mueve al nuevo nodo
    m.obtenerNodo(fila, columna).eliminarCriatura(this);
    m.obtenerNodo(nuevaFila, nuevaCol).agregarCriatura(this);

    cout << "El enano " << nombre << " se movió a Fila: " << nuevaFila + 1 << " Columna: " << nuevaCol + 1
         << " | Bioma actual: " << m.obtenerNodo(nuevaFila, nuevaCol).getTipo() << endl;

    // Actualizar posición interna
    setPosicion(nuevaFila, nuevaCol);
}

void enano::evolucion(mapa &m) {
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

            cout << "El enano " << nombre << " evolucionó a " << opcion << endl;
        }
    }
}

string enano::getNombre() const {
    return nombre;
}

void enano::setPosicion(int f, int c) {
    fila = f;
    columna = c;
}

void enano::morir(mapa &m) {
    cout << "El enano " << nombre << " ha perecido." << endl;
    m.obtenerNodo(fila, columna).eliminarCriatura(this);
    setVida(0);
    delete this;
}
