//
// Created by Julian on 30/04/2025.
//

#ifndef CRIATURA_H
#define CRIATURA_H

#include <iostream>
#include "mapa.h"
using namespace std;

class mapa;

class criatura {
public:
    // par de funciones virtuales para que cada criatura modifique esto a su gusto.
    virtual string getNombre() const = 0;
    virtual ~criatura() = default;
    virtual void actuar(mapa &m) = 0;
};



#endif //CRIATURA_H
