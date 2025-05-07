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
    int numeroAleatorio =  rand() % 3; // Número entre 0 y 2
    if (numeroAleatorio == 1) {
        int vidaRegenerada = puntos + (rand() % 2 ); // Vida a regenerar
        return vidaRegenerada;  // Retorna los puntos.
    }
}
