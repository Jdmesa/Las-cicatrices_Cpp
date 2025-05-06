//
// Created by Julian on 3/05/2025.
//

#include "regeneracion.h"

#include <cstdlib>

regeneracion::regeneracion(int p) : puntos(p) {}

int regeneracion::getPuntos() const {
    return puntos;
}

void regeneracion::setPuntos(int p) {
    puntos = p;
}

int regeneracion::regenerar() {
    int puntosAleatorios = rand() % 3; // Numero entre 0 y 2
    setPuntos(puntos*puntosAleatorios); // Se multiplica los puntos actuales por los puntos aleatorios para la cantidad de vida a regenerar
    return getPuntos(); //Retorna los puntos.
}
