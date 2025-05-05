//
// Created by Julian on 3/05/2025.
//

#include "dragon.h"

dragon::dragon(const string& nombre, int& fila, int& columna): nombre(nombre), criatura(fila, columna, 5) {}

void dragon::moverse(mapa &m) {
    int nuevaFila = fila + (rand() % 4 - 1) ;
    int nuevaCol = columna + (rand() % 4 - 1) ;

    //Limitar dentro del mapa
    nuevaFila = max(0, min(nuevaFila, m.getFilas() - 1));
    nuevaCol = max(0, min(nuevaCol, m.getColumnas() - 1));

    if (nuevaFila == fila && nuevaCol == columna) return;

    m.obtenerNodo(fila,columna).eliminarCriatura(this);
    m.obtenerNodo(nuevaFila,nuevaCol).agregarCriatura(this);

    cout << nombre << "-> Moved, before : " << "Fila: " << fila+1 << " Columna: " << columna+1;
    cout << "  After: " << "Fila: " << nuevaFila+1 << " Columna: " << nuevaCol+1 << " | Bioma actual: " << m.obtenerNodo(nuevaFila,nuevaCol).getTipo() << endl;

    setPosicion(nuevaFila,nuevaCol);


}

void dragon::evolucion(mapa &m) {
    //TODO: implementar evolucion.
}

void dragon::setPosicion(int f, int c) {
    fila = f;
    columna = c;
}

string dragon::getNombre() const {
    return nombre;
}

int dragon::getFila() const {
    return fila;
}

int dragon::getColumna() const {
    return columna;
}
