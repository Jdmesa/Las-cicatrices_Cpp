//
// Created by Julian on 30/04/2025.
//

#ifndef CRIATURAPRUEBA_H
#define CRIATURAPRUEBA_H

#include <iostream>
#include "../Atributos/criatura.h"

using namespace std;

class criaturaPrueba : public criatura {
private:
    string nombre;
    int fila;
    int columna;
    bool vive;
public:
    criaturaPrueba(const string& nombre, int fila, int columna);

    void moverse(mapa &m) override;
    void evolucion(mapa &m) override;
    void setPosicion(int f, int c);
    void morir() override;

    string getNombre() const override;
    bool getvida()  {return vive = true;}

    int getFila() const;
    int getColumna() const;
};



#endif //CRIATURAPRUEBA_H
