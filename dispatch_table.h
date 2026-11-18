#ifndef DISPATCH_TABLE_H
#define DISPATCH_TABLE_H

#include "ranking.h"
typedef void (*decision_usuario)(Ranking *jugador);

void esperar_enter(void);
void jugar(Ranking *jugador);
void ver_puntaje(Ranking *jugador);
void reglas(Ranking *jugador);
void salir(Ranking *jugador);

extern const decision_usuario TABLA_OPERACION[SALIR + 1];

#endif