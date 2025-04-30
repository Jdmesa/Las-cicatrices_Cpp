//
// Created by Julian on 30/04/2025.
//

#include "criaturaPrueba.h"

criaturaPrueba::criaturaPrueba(const string &nombre, const int& fila, const int& columna) : nombre(nombre), fila(fila), columna(columna) {}

string criaturaPrueba::getNombre() const { return nombre; }

int criaturaPrueba::getFila() const {
    return fila;
}

int criaturaPrueba::getColumna() const {
    return columna;
}

void criaturaPrueba::actuar(mapa& m) {
    // Movimiento aleatorio a nodo vecino
    int nuevaFila = fila + (rand() % 3 - 1);     // -1, 0, 1
    int nuevaCol = columna + (rand() % 3 - 1);   // -1, 0, 1

    // Limitar dentro del mapa
    nuevaFila = max(0, min(nuevaFila, m.getFilas() - 1));
    nuevaCol = max(0, min(nuevaCol, m.getColumnas() - 1));

    if (nuevaFila == fila && nuevaCol == columna) return;  // No se mueve si es la misma posicion generada

    // Se mueve al nuevo nodo
    m.obtenerNodo(fila, columna).eliminarCriatura(this);
    m.obtenerNodo(nuevaFila, nuevaCol).agregarCriatura(this);

    // Actualizar posición interna de la clase.
    fila = nuevaFila;
    columna = nuevaCol;
}
void criaturaPrueba::setPosicion(int f, int c) {
    fila = f;
    columna = c;
}