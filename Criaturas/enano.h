//
// Created by Julian on 3/05/2025.
//

#ifndef ENANO_H
#define ENANO_H
#include "../Atributos/criatura.h"
#include "../Atributos/regeneracion.h"


class enano : public criatura, public regeneracion {
private:
    string nombre;
public:
    enano(const string& nombre, int fila, int columna);

    void moverse(mapa &m) override;
    void evolucion(mapa &m) override;
    void morir() override;
    void recibirAtaque(int danio) override;
    string getNombre() const override;
    void pelear(criatura &otra) override;

};



#endif //ENANO_H
