//
// Created by Julian on 30/04/2025.
//

#ifndef CRIATURA_H
#define CRIATURA_H

#include <iostream>
#include "../Ecosistema/mapa.h"
using namespace std;

class mapa;

class criatura {
    protected:
    string cicloEv; // Existiran 4: crio, adulto, evolutivo, zombie, muerto
    int fila;
    int columna;
    int vida;
public:
    criatura(int& fila, int& columna, int vida);
    // par de funciones virtuales para que cada criatura modifique esto a su gusto.
    virtual string getNombre() const = 0;
    virtual ~criatura() = default;
    virtual void moverse(mapa &m) = 0;
    virtual void evolucion(mapa &m) = 0;
    virtual void morir() = 0;
    virtual void pelear(criatura *otra) = 0;
    virtual void recibirAtaque(int danio) = 0;
    void setPosicion(int f, int c);
    void setCiclo(string ciclo);
    void setVida(int v);

    int getVida() const;
    int getFila() const;
    int getColumna() const;
};



#endif //CRIATURA_H
