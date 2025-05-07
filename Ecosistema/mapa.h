//
// Created by Julian on 30/04/2025.
//

#ifndef MAPA_H
#define MAPA_H

#include "nodo.h"
#include <vector>
using namespace std;
class mapa {

private:
    int filas;
    int columnas;
    char bioma;
    vector<vector<nodo>> matriz;

    public:
    mapa(int filas, int columnas, char bioma);

    nodo& obtenerNodo(int fila, int columna);
    void moverCriaturas();
    void evolucionarCriaturas(mapa &m);
    void mostrarMapa() const;
    int getTotalCriaturasEnMapa();
    int getFilas() const;
    int getColumnas() const;

};



#endif //MAPA_H
