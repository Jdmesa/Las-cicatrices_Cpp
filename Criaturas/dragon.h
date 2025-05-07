//
// Created by Julian on 3/05/2025.
//

#ifndef DRAGON_H
#define DRAGON_H
#include "../Atributos/criatura.h"
#include "../Atributos/regeneracion.h"
#include "../Atributos/volador.h"


class dragon : public criatura, public volador, public regeneracion {
private:
    string nombre;
    public:
    dragon(const string& nombre, int& fila, int& columna);

    void moverse(mapa &m) override;
    void evolucion(mapa &m) override;
    void morir() override;
    void pelear(criatura *otra) override;
    void recibirAtaque(int danio) override;
    string getNombre() const override;

};



#endif //DRAGON_H
