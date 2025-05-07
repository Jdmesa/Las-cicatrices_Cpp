//
// Created by Julian on 6/05/2025.
//

#include "gigante.h"
#include <random>
#include <algorithm> // Para min y max

gigante::gigante(const string &nombre, int fila, int columna) : criatura(fila, columna, 6) {
}

void gigante::morir(mapa &m) {
    cout << nombre << " ha perecido." << endl;
    m.obtenerNodo(fila, columna).eliminarCriatura(this);
    setVida(0);
    delete this;
}
void gigante::moverse(mapa &m) {
    int nuevaFila = fila + (rand() % 3 - 1);
    int nuevaCol = columna + (rand() % 3 - 1);

    // Limitar dentro del mapa
    nuevaFila = max(0, std::min(nuevaFila, m.getFilas() - 1));
    nuevaCol = max(0, std::min(nuevaCol, m.getColumnas() - 1));

    // No moverse si no cambia de posición
    if (nuevaFila == fila && nuevaCol == columna) return;

    // Actualizar posición en el mapa
    m.obtenerNodo(fila, columna).eliminarCriatura(this);
    m.obtenerNodo(nuevaFila, nuevaCol).agregarCriatura(this);

    // Mostrar información del movimiento
    cout << nombre << " se movio a " << "Fila: " << nuevaFila+1 << " Columna: " << nuevaCol+1 << " | Bioma actual: " << m.obtenerNodo(nuevaFila,nuevaCol).getTipo() << endl;

    setPosicion(nuevaFila,nuevaCol);
}

void gigante::evolucion(mapa &m) {
    int numeroAdivinador = 5;
    random_device rd2;
    mt19937 gen2(rd2());
    uniform_int_distribution<> distribucionRango(0, 6); // Rango de 0 a 6

    int numeroEnRangoRandom = distribucionRango(gen2);
    if (numeroEnRangoRandom == numeroAdivinador) {
        if (cicloEv == "zombie") {
            morir(m);
        } else {
            random_device rd3;
            mt19937 gen3(rd3());
            uniform_int_distribution<> distribucionOpciones(0, 2);
            vector<string> opciones2 = { "adulto", "evolutivo", "zombie" };
            int indice = distribucionOpciones(gen3);
            string opcion = opciones2[indice];
            setCiclo(opcion);
        }
    }
}

string gigante::getNombre() const {
    return nombre;
}

int gigante::getFila() const {
    return fila;
}

int gigante::getColumna() const {
    return columna;
}
