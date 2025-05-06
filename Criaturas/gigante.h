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

        void morir(mapa &m) override;
        void moverse(mapa &m) override;
        void evolucion(mapa &m) override;
        void setPosicion(int f, int c);

        string getNombre() const override;

        int getFila() const;
        int getColumna() const;

};



#endif //GIGANTE_H
