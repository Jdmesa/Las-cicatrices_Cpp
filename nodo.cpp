//
// Created by Julian on 23/04/2025.
//

#include "nodo.h"
#include <algorithm>

nodo::nodo(int fila, int columna, const string &tipo) : fila(fila), columna(columna), tipo(tipo) {}

int nodo::getFila() const {
    return fila;
}

int nodo::getColumna() const {
    return columna;
}

string nodo::getTipo() const {
    return tipo;
}

void nodo::setTipo(const string &tipoNuevo) {
    tipo = tipoNuevo;
}

void nodo::agregarCriatura(Criatura *c) {
    criaturas.push_back(c);
}

void nodo::eliminarCriatura(Criatura *c) {
    criaturas.erase(remove(criaturas.begin(), criaturas.end(), c), criaturas.end());
}

const vector<Criatura *> & nodo::getCriaturas() const {
    return criaturas;
}
