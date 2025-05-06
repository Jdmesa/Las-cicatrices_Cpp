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
public:
    criaturaPrueba(const string& nombre, int fila, int columna, mapa& m);
    ~criaturaPrueba() override;
    void moverse(mapa &m) override;
    void evolucion(mapa &m) override;
    void morir(mapa &m) override;

    string getNombre() const override;

    bool getvida();
    int getFila() const;
    int getColumna() const;
};



#endif //CRIATURAPRUEBA_H
