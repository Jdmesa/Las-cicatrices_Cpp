//
// Created by Julian on 2/05/2025.
//

#include "ecosistema.h"
#include "criaturaPrueba.h"
ecosistema::ecosistema(int f, int c, char bioma, int ciclos) : m(f,c,bioma), ciclos(ciclos) {
    if (bioma == 'b') {
        // Mapa 5x5, 20 ciclos
        criatura* dragon2 = new criaturaPrueba("Dragon demoledor", 1, 2);
        criatura* ada = new criaturaPrueba("Hada Maestra", 2,2);
        m.obtenerNodo(1,2).agregarCriatura(dragon2);
        m.obtenerNodo(2,2).agregarCriatura(ada);

    } else if (bioma == 'v') {

        criatura* dragonDeFuego = new criaturaPrueba("Dragon demoledor", 1, 2);
        criatura* adaPoderosa = new criaturaPrueba("Hada Maestra", 2,2);
        m.obtenerNodo(1,2).agregarCriatura(dragonDeFuego);
        m.obtenerNodo(2,2).agregarCriatura(adaPoderosa);

    }
    ciclo();
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
    }
}

int ecosistema::getCiclos() const {
    return ciclos;
}