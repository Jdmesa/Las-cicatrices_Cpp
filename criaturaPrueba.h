//
// Created by Julian on 30/04/2025.
//

#ifndef CRIATURAPRUEBA_H
#define CRIATURAPRUEBA_H

#include <iostream>
#include "criatura.h"

using namespace std;

class criaturaPrueba : public criatura {
private:
    string nombre;
public:
    criaturaPrueba(const string& nombre, int& fila, int& columna);

    void moverse(mapa &m) override;
    void evolucion() override;
    void setPosicion(int f, int c);

    string getNombre() const override;

    int getFila() const;
    int getColumna() const;
};



#endif //CRIATURAPRUEBA_H
