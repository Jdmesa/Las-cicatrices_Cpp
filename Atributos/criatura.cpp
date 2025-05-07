//
// Created by Julian on 30/04/2025.
//

#include "criatura.h"
criatura::criatura(int& fila, int& columna, int vida) : fila(fila), columna(columna), vida(vida), cicloEv("crio")  /* Ciclo Evolutivo inicial*/{}

void criatura::setPosicion(int f, int c) {
    fila = f;
    columna = c;
}

void criatura::setCiclo(string ciclo) {
    cicloEv = ciclo;
}

void criatura::setVida(int v) {
    vida = v;
}

int criatura::getVida() const {
    return vida;
}

int criatura::getFila() const {
    return fila;
}

int criatura::getColumna() const {
    return columna;
}
