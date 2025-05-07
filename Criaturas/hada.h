//
// Created by Julian on 3/05/2025.
//

#ifndef HADA_H
#define HADA_H
#include "../Atributos/criatura.h"
#include "../Atributos/fantasma.h"


class hada : public criatura, public fantasma {
    private:
    string nombre;
public:
    hada(const string& nombre, int fila, int columna);

    void morir() override;
    void moverse(mapa &m) override;
    void evolucion(mapa &m) override;
    void pelear(criatura &otra) override;
    void recibirAtaque(int danio) override;

    string getNombre() const override;

};



#endif //HADA_H
