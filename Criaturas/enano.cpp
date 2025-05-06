 git//
// Created by Julian on 3/05/2025.
//

#include "enano.h"

enano::enano(string nombre, int fila, int columna) : nombre(nombre), criatura(fila, columna, 2) {}

void enano::moverse(mapa &m) {
// TODO: Implementar funcion de moverse

}

void enano::evolucion(mapa &m) {
// TODO: Implementar evolucion
}

string enano::getNombre() const {
    return nombre;
}

void enano::setPosicion(int f, int c) {
    fila = f;
    columna = c;
}

void enano::morir(mapa &m) {
    //TODO: Implementar morir criatura
}
