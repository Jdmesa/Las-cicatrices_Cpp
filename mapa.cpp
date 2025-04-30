//
// Created by Julian on 30/04/2025.
//

#include "mapa.h"
#include "criatura.h"

mapa::mapa(int filas, int columnas) : filas(filas), columnas(columnas) {
    for (int i = 0; i < filas; ++i) {
        vector<nodo> filaActual;
        for (int j = 0; j < columnas; ++j) {
            filaActual.emplace_back(i,j, "neutro");
        }
        matriz.push_back(filaActual);
    }
}

nodo& mapa::obtenerNodo(int fila, int columna) {
    if (fila <0 || fila>=filas || columna <0 || columna>=columnas) {
        throw out_of_range("Coordenadas fuera de los limites.");
    }
    return matriz[fila][columna];
}

void mapa::mostrarMapa() const {
    for (const auto& fila: matriz) {
        for (const auto& nodo : fila) {
            char simbolo = ' ';
            string tipo = nodo.getTipo();

            if (tipo == "neutro") simbolo = 'N';
            else if (tipo == "bosque") simbolo = 'B';
            else if (tipo == "agua") simbolo = 'A';
            else simbolo = '?';

            if (!nodo.getCriaturas().empty()) {
                simbolo = nodo.getCriaturas().front()->getNombre()[0];
            }

            cout << "[" << simbolo << "]";
        }
        cout << "\n";
    }
}

int mapa::getFilas() const {
    return filas;
}
int mapa::getColumnas() const {
    return columnas;
}
