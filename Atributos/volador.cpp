//
// Created by Julian on 3/05/2025.
//

#include "volador.h"

volador::volador(bool volar) : volar(volar) {
}

bool volador::getVuela() const {
    return volar;
}
