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
    int fila;
    int columna;
    bool vive;
public:
    criaturaPrueba(const string& nombre, const int& fila, const int& columna, bool& vive);

    void moverse(mapa &m) override;
    void evolucion(mapa &m) override;
    void setPosicion(int f, int c);
    void morir() override;

    string getNombre() const override;
    bool EstaVivo()  {return vive = true;}

    int getFila() const;
    int getColumna() const;
};



#endif //CRIATURAPRUEBA_H
