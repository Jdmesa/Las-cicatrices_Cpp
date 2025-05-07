//
// Created by Julian on 23/04/2025.
//

#ifndef NODO_H
#define NODO_H

class criatura;
class mapa;

#include <iostream>
#include <vector>

using namespace std;

class nodo {
private:
    int fila;
    int columna;
    string tipo;
    vector<criatura*> criaturas;

    public:
    nodo(int fila, int columna, const string& tipo);

    int getFila() const;
    int getColumna() const;
    string getTipo() const;
    int getTotalCriaturas() const;

    void actuarCriaturas(mapa &m);
    void evolucionarCriaturas(mapa &m);
    void setTipo(const string& tipo);

    void agregarCriatura(criatura* criaturas);
    void eliminarCriatura(criatura* criatura);

    void eliminarMuertas();

    const vector<criatura*>& getCriaturas() const;


};



#endif //NODO_H
