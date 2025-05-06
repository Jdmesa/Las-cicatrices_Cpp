//
// Created by Julian on 2/05/2025.
//

#include "ecosistema.h"

#include <limits>
#include <random>

#include "../Criaturas/criaturaPrueba.h"
#include "../Criaturas/dragon.h"
#include "../Criaturas/enano.h"
#include "../Criaturas/hada.h"

string generarNombreAleatorioCriatura(string tipo) {
    string prefijo; // Primer nombre
    const char* sufijos[] = {"de Fuego", "Veloz", "Oscuro", "Radiante", "Maligno"}; // Segundo nombre
    if (tipo == "Dragon") {
        prefijo = "Dragon";
    } else if (tipo == "Hada") {
        prefijo = "Hada";
    } else if (tipo == "Enano") {
        prefijo = "Enano";
    }else if (tipo == "Gigante") {
        prefijo = "Gigante";
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion_sufijo(0, sizeof(sufijos) / sizeof(sufijos[0]) - 1);
    // Para seleccionar aleatoriamente el sufijo de la criatura

    return string(prefijo + " " + sufijos[distribucion_sufijo(gen)]);
    // Retorna el prefijo + el sufijo
}
vector<criatura*> generacionCriaturas(int cantidad, mapa& m, int f, int c) {
    vector<criatura*> criaturas;
    random_device rd;
    mt19937 gen(rd());


    for (int i = 0; i < cantidad; ++i) {
        uniform_int_distribution<> distribucion_fila(0, f - 1); // Filas en el rango de 0 a fila - 1
        uniform_int_distribution<> distribucion_columna(0, c - 1); // Columnas en el rango de 0 a columna - 1
        uniform_int_distribution<> tipo_distribucion(0, 2);   // 3 tipos: 0 = dragón, 1 = hada, 2 = enano

        int fila_aleatoria = distribucion_fila(gen); // Seleccion de filas, columnas y el tipo de criatura a generar.
        int columna_aleatoria = distribucion_columna(gen);
        int tipo = tipo_distribucion(gen);

        string nombre_aleatorio;

        criatura* nueva_criatura = nullptr;
        switch (tipo) {
            case 0:
                nombre_aleatorio = generarNombreAleatorioCriatura("Dragon");
                nueva_criatura = new dragon(nombre_aleatorio, fila_aleatoria, columna_aleatoria);
            break;
            case 1:
                nombre_aleatorio = generarNombreAleatorioCriatura("Hada");
                nueva_criatura = new hada(nombre_aleatorio, fila_aleatoria, columna_aleatoria);
            break;
            case 2:
                nombre_aleatorio = generarNombreAleatorioCriatura("Enano");
                nueva_criatura = new enano(nombre_aleatorio, fila_aleatoria, columna_aleatoria);
            break;
        }
        cout << nueva_criatura->getNombre() << endl;
        criaturas.push_back(nueva_criatura);
    }
    return criaturas;
}

ecosistema::ecosistema(int f, int c, char bioma, int ciclos) : m(f,c,bioma), ciclos(ciclos) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(10,50); // Minimo 10 criaturas, maximo 50.
    vector<criatura*> mis_criaturas = generacionCriaturas(distribution(gen), m, f, c);

    cout << "Criaturas iniciales: " << mis_criaturas.size() << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ciclo(f,c);

    for (auto& criatura : mis_criaturas) {
        delete criatura;
    }
    mis_criaturas.clear();

}

void ecosistema::ciclo(int f, int c) {
    int filas, columnas;
    filas = f;
    columnas = c;

    for (int i = 1; i < ciclos+1; i++) {
        cout << "Ciclo #" << i << endl;
        for (int j = 0; j < filas; j++) {
            for (int k = 0; k < columnas; k++) {
                if (!m.obtenerNodo(j,k).getCriaturas().empty()) {
                    m.obtenerNodo(j,k).actuarCriaturas(m);
                }
            }
        }
        m.evolucionarCriaturas(m);
        m.mostrarMapa();
        if (i < ciclos) {
            cout << "Presiona [ENTER] para continuar al ciclo #" << i+1 << endl;
            cin.get();
        }

    }
}

int ecosistema::getCiclos() const {
    return ciclos;
}