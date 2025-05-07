//
// Created by Julian on 3/05/2025.
//
#include <cstdlib>
#include <ctime>
#include "hada.h"
#include <random>
#include <algorithm> // Para min y max

hada::hada(const string &nombre, int fila, int columna) : nombre(nombre), criatura(fila, columna, 3), fantasma(true) {
}

void hada::morir() {
    cout << nombre << " ha perecido." << endl;
    setVida(0);
}

void hada::moverse(mapa &m) {

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

void hada::evolucion(mapa &m){
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
        }
    }
}

void hada::pelear(criatura *otra) {
    int danio = 2 + (rand() % 3); // Maximo de dano 4, minimo 2.
    int cantidadVida = otra->getVida() - danio; // Se calcula la vida final de la criatura
    cout << nombre << " ha lanzado un hechizo a " << otra->getNombre();
    otra->recibirAtaque(cantidadVida); // Se ejecuta que la otra criatura recibe el ataque
}

void hada::recibirAtaque(int danio) {
    cout << " es fantasma y a recibido minimo daño." << endl;
    setVida(vida - 1);
    //En este caso la vida del hada recibe minimo dano debido a que tiene el atributo fantasma
    if (vida <= 0) {
        morir();
    }
}


string hada::getNombre() const {
    return nombre;
}

