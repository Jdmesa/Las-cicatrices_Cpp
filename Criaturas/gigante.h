//
// Created by Julian on 6/05/2025.
//

#ifndef GIGANTE_H
#define GIGANTE_H

#include <iostream>

#include "../Atributos/criatura.h"

class mapa;
using namespace std;

class gigante : public criatura {
    private:
        string nombre;
    public:
        gigante(const string& nombre, int fila, int columna);

        void morir() override;
        void moverse(mapa &m) override;
        void evolucion(mapa &m) override;
        void pelear(criatura *otra) override;
        void recibirAtaque(int danio) override;
        string getNombre() const override;


};



#endif //GIGANTE_H
