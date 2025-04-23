//
// Created by Julian on 23/04/2025.
//

#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
using namespace std;

class Criatura;

class nodo {
private:
    int fila;
    int columna;
    string tipo;
    vector<Criatura*> criaturas;

    public:
    nodo(int fila, int columna, const string& tipo);
    ~nodo();

    int getFila() const;
    int getColumna() const;
    string getTipo() const;

    void setTipo(const string& tipo);

    void agregarCriatura(Criatura* criaturas);
    void eliminarCriatura(Criatura* criatura);

    const vector<Criatura*>& getCriaturas() const;


};



#endif //NODO_H
