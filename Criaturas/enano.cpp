 //
// Created by Julian on 3/05/2025.
//
#include "enano.h"
#include <iostream>
#include <random>
#include <algorithm> // Para min y max
using namespace std;

enano::enano(const string& nombre, int fila, int columna) : nombre(nombre), criatura(fila, columna, 2), regeneracion(1) {
}

void enano::moverse(mapa &m) {
    // Movimiento aleatorio a nodo vecino
    int nuevaFila = fila + (rand() % 3 - 1);     // -1, 0, 1
    int nuevaCol = columna + (rand() % 3 - 1);   // -1, 0, 1

    // Limitar dentro del mapa
    nuevaFila = max(0, min(nuevaFila, m.getFilas() - 1));
    nuevaCol = max(0, min(nuevaCol, m.getColumnas() - 1));
    if (nuevaFila == fila && nuevaCol == columna) return;  // No se mueve si es la misma posición generada

    // Se mueve al nuevo nodo
    m.obtenerNodo(fila, columna).eliminarCriatura(this);
    m.obtenerNodo(nuevaFila, nuevaCol).agregarCriatura(this);

    cout << nombre << " se movio a " << "Fila: " << nuevaFila+1 << " Columna: " << nuevaCol+1 << " | Bioma actual: " << m.obtenerNodo(nuevaFila,nuevaCol).getTipo() << endl;

    // Actualizar posición interna
    setPosicion(nuevaFila, nuevaCol);
}

void enano::evolucion(mapa &m) {
    int numeroAdivinador = 5;
    random_device rd2;
    mt19937 gen2(rd2());
    uniform_int_distribution<> distribucionRango(0, 6); // Rango de 0 a 6

    int numeroEnRangoRandom = distribucionRango(gen2);
    if (numeroEnRangoRandom == numeroAdivinador) {
        if (cicloEv == "zombie") {
            morir();
        } else {
            random_device rd3;
            mt19937 gen3(rd3());
            uniform_int_distribution<> distribucionOpciones(0, 2);
            vector<string> opciones2 = { "adulto", "evolutivo", "zombie" };
            int indice = distribucionOpciones(gen3);
            string opcion = opciones2[indice];
            setCiclo(opcion);

            cout << nombre << " evolucionó a " << opcion << endl;
        }
    }
}

void enano::pelear(criatura *otra) {
    int danio = 1 + (rand() % 3); // Maximo de dano 4, minimo 2.
    int cantidadVida = otra->getVida() - danio; // Se calcula la vida final de la criatura
    cout << nombre << " le ha metido un picazo a " << otra->getNombre();
    otra->recibirAtaque(cantidadVida); // Se ejecuta que la otra criatura recibe el ataque
}

void enano::recibirAtaque(int danio){
    cout << " y quito " << min(danio, vida) << " puntos" << endl;
    setVida(min(danio, vida)); // Primero se establece el dano recibido
    if (vida <= 0) { // Si la vida es menor o igual a 0, muere.
        morir();
    } else { // De lo contrario, si tiene regeneracion (como es el caso del dragon), regenera, de lo contrario no.
        int puntosRegenerados = regenerar();
        if (puntosRegenerados == 0 ) {
            setVida(vida);
        } else {
            setVida(puntosRegenerados);
        }
        cout << nombre << " tiene regeneracion y ahora tiene " << vida << endl;
    }
}

string enano::getNombre() const {
    return nombre;
}

void enano::morir() {
    cout << nombre << " ha perecido." << endl;
    setVida(0);
}
