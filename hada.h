//
// Created by Julian on 3/05/2025.
//

#ifndef HADA_H
#define HADA_H
#include "criatura.h"


class hada : public criatura {
    private:
    string nombre;
public:
    hada(const string& nombre, int fila, int columna);

    void moverse(mapa &m) override;
    void evolucion() override;
    void setPosicion(int f, int c);

    string getNombre() const override;

    int getFila() const;
    int getColumna() const;
};



#endif //HADA_H
