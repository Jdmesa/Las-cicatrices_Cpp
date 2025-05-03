//
// Created by Julian on 3/05/2025.
//

#ifndef DRAGON_H
#define DRAGON_H
#include "criatura.h"


class dragon : public criatura {
private:
    string nombre;
    public:
    dragon(const string& nombre, int& fila, int& columna);

    void moverse(mapa &m) override;
    void evolucion() override;
    void setPosicion(int f, int c);

    string getNombre() const override;

    int getFila() const;
    int getColumna() const;
};



#endif //DRAGON_H
