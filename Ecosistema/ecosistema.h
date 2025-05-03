//
// Created by Julian on 2/05/2025.
//

#ifndef ECOSISTEMA_H
#define ECOSISTEMA_H

#include "mapa.h"
class ecosistema {
private:
  mapa m;
  int ciclos;
  public:
  ecosistema(int f, int c, char b, int ciclos);
  int getCiclos() const;
  void ciclo();

};



#endif //ECOSISTEMA_H
