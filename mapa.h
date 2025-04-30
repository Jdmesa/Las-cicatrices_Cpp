//
// Created by Julian on 30/04/2025.
//

#ifndef MAPA_H
#define MAPA_H

#include "nodo.h"
#include <vector>

class mapa {

private:
    int filas;
    int columnas;
    vector<vector<nodo>> matriz;

    public:
    mapa(int filas, int columnas);

    nodo& obtenerNodo(int fila, int columna);

    void mostrarMapa() const;
    int getFilas() const;
    int getColumnas() const;

};



#endif //MAPA_H
