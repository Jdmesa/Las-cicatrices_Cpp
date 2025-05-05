//
// Created by Julian on 30/04/2025.
//

#include "criaturaPrueba.h"
#include "../Atributos/criatura.h"
#include <random>

#include "dragon.h"

criaturaPrueba::criaturaPrueba(const string &nombre, int fila, int columna) : criatura(fila, columna), nombre(nombre), fila(fila), columna(columna), vive(vive) {}

string criaturaPrueba::getNombre() const { return nombre; }

int criaturaPrueba::getFila() const {
    return fila;
}

int criaturaPrueba::getColumna() const {
    return columna;
}

void criaturaPrueba::moverse(mapa& m) {
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
    // Tener en cuenta:
    // 1) Las filas son verticales, van hacia abajo.
    // 2) Las columnas son horizontales, van hacia la derecha.
    // 3) En el programa todas las filas y columnas inician en 0, pero visualmente se le muestra al usuario desde 1.

    cout << nombre << "-> Moved, before : " << "Fila: " << fila+1 << " Columna: " << columna+1;
    cout << "  After: " << "Fila: " << nuevaFila+1 << " Columna: " << nuevaCol+1 << " | Bioma actual: " << m.obtenerNodo(nuevaFila,nuevaCol).getTipo() << endl;
    // Actualizar posición interna de la clase.
    setPosicion(nuevaFila, nuevaCol);
}

void criaturaPrueba::evolucion(mapa &m) {
    int numeroAdivinador = 5;
    random_device rd2;
    mt19937 gen2(rd2());
    uniform_int_distribution<> distribucionRango(0, 6); // Rango de 0 a 10

    int numeroEnRangoRandom = distribucionRango(gen2);
    if (numeroEnRangoRandom == numeroAdivinador) {
        if (cicloEv == "zombie") { //En caso de que la criatura evolucione a zombie, perecerá
            morir(m);

        }else {
            random_device rd3;
            mt19937 gen3(rd3());
            uniform_int_distribution<> distribucionOpciones(0, 2);
            vector<string> opciones2 = { "adulto", "evolutivo", "zombie"};
            int indice = distribucionOpciones(gen3);
            string opcion = opciones2[indice];
            string cicloEv = opcion; // Asigna la opción a tu variable cicloEv

            cout << nombre << "-> Evolucionó a " << opcion << endl;
        }
    }
}

void criaturaPrueba::morir(mapa &m) {
    vive = false;
    m.obtenerNodo(fila, columna).eliminarCriatura(this);
    cout << nombre << " Ha perecido" << endl;
}


void criaturaPrueba::setPosicion(int f, int c) {
    fila = f;
    columna = c;
}
