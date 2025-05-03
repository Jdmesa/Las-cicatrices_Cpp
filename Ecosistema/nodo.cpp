//
// Created by Julian on 23/04/2025.
//

#include "nodo.h"
#include "../Atributos/criatura.h"
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

int nodo::getTotalCriaturas() const {
    return criaturas.size();
}

void nodo::actuarCriaturas(mapa &m) {
    for (auto criatura : criaturas) {
        criatura->moverse(m);
    }
}

void nodo::evolucionarCriaturas(mapa &m) {
    for (auto criatura : criaturas) {
        criatura->evolucion(m);
    }
}

void nodo::setTipo(const string &tipoNuevo) {
    tipo = tipoNuevo;
}

void nodo::agregarCriatura(criatura *c) {
    criaturas.push_back(c);
}

void nodo::eliminarCriatura(criatura *c) {
    criaturas.erase(remove(criaturas.begin(), criaturas.end(), c), criaturas.end());
}

const vector<criatura *> & nodo::getCriaturas() const {
    return criaturas;
}
