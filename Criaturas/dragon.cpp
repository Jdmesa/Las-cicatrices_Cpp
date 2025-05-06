//
// Created by Julian on 3/05/2025.
//
#include <random>
#include <algorithm> // Para min y max
#include "dragon.h"

dragon::dragon(const string& nombre, int& fila, int& columna): nombre(nombre), criatura(fila, columna, 5) {}
dragon::~dragon() {
    cout << "Dragon ha sido destruido" << endl;
}

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

void dragon::evolucion(mapa &m){
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

            cout << "El dragon " << nombre << " evolucionó a " << opcion << endl;
        }
    }
}


void dragon::morir(mapa &m){
    vive = false;
    m.obtenerNodo(fila, columna).eliminarCriatura(this);
    cout << nombre << " Ha perecido" << endl;
    dragon::~dragon();
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

bool dragon::getVive() {
    return vive;
}