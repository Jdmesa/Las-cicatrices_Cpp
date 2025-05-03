//
// Created by Julian on 3/05/2025.
//

#include "hada.h"

hada::hada(const string &nombre, int fila, int columna) : nombre(nombre), criatura(fila, columna) {
}

void hada::moverse(mapa &m) {
    //TODO: Agregar funcionalidad de moverse
}

void hada::evolucion(mapa &m) {
    //TODO: Agregar funcionalida de evolucion.
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
