//
// Created by Julian on 3/05/2025.
//
#include <cstdlib>
#include <ctime>
#include "hada.h"

hada::hada(const string &nombre, int fila, int columna) : nombre(nombre), criatura(fila, columna) {
}

void hada::moverse(mapa &m) {
    //TODO: Agregar funcionalidad de moverse
    int nuevaFila = fila + (rand() % 3 - 1);
    int nuevaCol = columna + (rand() % 3 - 1);

    // Limitar dentro del mapa
    nuevaFila = std::max(0, std::min(nuevaFila, m.getFilas() - 1));
    nuevaCol = std::max(0, std::min(nuevaCol, m.getColumnas() - 1));

    // No moverse si no cambia de posición
    if (nuevaFila == fila && nuevaCol == columna) return;

    // Actualizar posición en el mapa
    m.obtenerNodo(fila, columna).eliminarCriatura(this);
    m.obtenerNodo(nuevaFila, nuevaCol).agregarCriatura(this);

    // Mostrar información del movimiento
    std::cout << nombre << " (Hada)-> Se movió de Fila: " << fila + 1 << " Columna: " << columna + 1;
    std::cout << " a Fila: " << nuevaFila + 1 << " Columna: " << nuevaCol + 1;
    std::cout << " | Bioma actual: " << m.obtenerNodo(nuevaFila, nuevaCol).getTipo() << std::endl;

    // Actualizar la posición interna
    setPosicion(nuevaFila, nuevaCol);
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
