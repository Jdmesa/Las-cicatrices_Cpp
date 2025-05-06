//
// Created by Julian on 30/04/2025.
//

#include "mapa.h"
#include "nodo.h"
#include "../Atributos/criatura.h"
#include <random>

using namespace std;

mapa::mapa(int filas, int columnas, char bioma) : filas(filas), columnas(columnas), bioma(bioma) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion; // Declaramos la distribución aquí

    vector<string> opciones;
    switch (bioma) {
        case 'b': //Boscoso
            opciones = {"denso", "claro", "oscuro"};
            distribucion = uniform_int_distribution<>(0, opciones.size() - 1);
        break;
        case 'v': //Volcanico
            opciones = {"roca", "seniza", "fumarolas"};
            distribucion = uniform_int_distribution<>(0, opciones.size() - 1);
        break;
        default:
            // Puedes agregar un caso por defecto si el bioma no coincide con 'b' o 'v'
                return; // O realizar alguna acción por defecto
    }

    // Llenar la matriz con el bioma seleccionado aleatoriamente
    for (int i = 0; i < filas; ++i) {
        vector<nodo> filaActual;
        for (int j = 0; j < columnas; ++j) {
            int indiceGenerado = distribucion(gen);
            auto it = opciones.begin();
            advance(it, indiceGenerado);
            string opcionSeleccionada = *it;
            filaActual.emplace_back(i,j,opcionSeleccionada);
        }
        matriz.push_back(filaActual);
    }
}

nodo& mapa::obtenerNodo(int fila, int columna) {
    if (fila <0 || fila>=filas || columna <0 || columna>=columnas) {
        throw out_of_range("Coordenadas fuera de los limites.");
    }
    return matriz[fila][columna];
}

void mapa::evolucionarCriaturas(mapa &m) {
   for (auto& fila : matriz) {
       for (auto& nodo : fila) {
           nodo.evolucionarCriaturas(m);
       }
   }
}

void mapa::mostrarMapa() const {
    char caracter = '#';
    string cadena(filas*3, caracter);
    cout << cadena << endl;
    for (const auto& fila: matriz) {
        for (const auto& nodo : fila) {
            char simbolo = toupper(nodo.getTipo().front());
            cout << "[" << simbolo << "]";
        }
        cout << "\n";
    }
    cout << cadena << endl;
}

int mapa::getFilas() const {
    return filas;
}
int mapa::getColumnas() const {
    return columnas;
}
