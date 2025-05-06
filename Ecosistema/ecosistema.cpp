//
// Created by Julian on 2/05/2025.
//

#include "ecosistema.h"

#include <limits>
#include <random>

#include "../Criaturas/criaturaPrueba.h"

string generarNombreAleatorioCriatura() {
    static const char* prefijos[] = {"Dragón", "Hada", "Trasgo", "Duende", "Espectro"}; // Primer nombre
    static const char* sufijos[] = {"de Fuego", "Veloz", "Oscuro", "Radiante", "Maligno"}; // Segundo nombre

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion_prefijo(0, sizeof(prefijos) / sizeof(prefijos[0]) - 1); // Seleccion aleatoria
    uniform_int_distribution<> distribucion_sufijo(0, sizeof(sufijos) / sizeof(sufijos[0]) - 1);

    return string(prefijos[distribucion_prefijo(gen)]) + " " + sufijos[distribucion_sufijo(gen)];
}
vector<criatura*> crearMultiplesCriaturasPrueba(int cantidad, mapa& m) {
    vector<criatura*> criaturas;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion_fila(0, 4);   // Rangos aleatorios para fila
    uniform_int_distribution<> distribucion_columna(0, 4); // Rangos aleatorios para columna

    for (int i = 0; i < cantidad; ++i) {
        string nombre_aleatorio = generarNombreAleatorioCriatura();
        int fila_aleatoria = distribucion_fila(gen);
        int columna_aleatoria = distribucion_columna(gen);
        criaturas.push_back(new criaturaPrueba(nombre_aleatorio, fila_aleatoria, columna_aleatoria, m));
    }
    return criaturas;
}

ecosistema::ecosistema(int f, int c, char bioma, int ciclos) : m(f,c,bioma), ciclos(ciclos) {

    int numero_criaturas = 10;
    vector<criatura*> mis_criaturas = crearMultiplesCriaturasPrueba(numero_criaturas, m);

    std::cout << "Se crearon " << mis_criaturas.size() << " criaturas de prueba:" << std::endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    ciclo();

    for (auto& criatura : mis_criaturas) {
        delete criatura;
    }
    mis_criaturas.clear();


}

void ecosistema::ciclo() {
    int filas, columnas;
    filas = m.getFilas();
    columnas = m.getColumnas();

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