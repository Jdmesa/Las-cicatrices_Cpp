//
// Created by Julian on 3/05/2025.
//

#ifndef ENANO_H
#define ENANO_H
#include "../Atributos/criatura.h"


class enano : public criatura {
private:
    string nombre;
    int fila;
    int columna;
public:
    enano(string nombre, int fila, int columna);

    void moverse(mapa &m) override;
    void evolucion(mapa &m) override;
    void morir() override;
    string getNombre() const override;

    void setPosicion(int f, int c);

};



#endif //ENANO_H
