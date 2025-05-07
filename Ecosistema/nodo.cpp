//
// Created by Julian on 23/04/2025.
//

#include "nodo.h"
#include "../Atributos/criatura.h"
#include <algorithm>
#include <random>

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
    // getCriaturas y si hay 2 o mas criaturas -> Pelear
    // Luego, si hay 2 o más, que se peleen dos aleatorias
    if (getTotalCriaturas() >= 2) {
        const vector<criatura*>& criaturitas = getCriaturas(); // Obtener todas las criaturas que estan en el nodo.

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, criaturitas.size() - 1); //Selecciona una posicion aleatoria dentro del vector criaturas

        int idx1 = dist(gen);
        int idx2 = dist(gen);
        while (idx2 == idx1) { // Mientras que las posiciones sean iguales, generara otra posicion.
            idx2 = dist(gen);
        }

        criatura* c1 = criaturitas[idx1];
        criatura* c2 = criaturitas[idx2]; //Seleccion de criatura en base a la posicion en el vector

        // Pelea mutua
        c1->pelear(*c2);
        c2->pelear(*c1);
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
