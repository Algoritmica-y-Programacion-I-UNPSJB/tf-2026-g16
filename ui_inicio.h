#ifndef UI_INICIO_H
#define UI_INICIO_H
#include "ranking.h"

// Muestra el menu, pide el nombre, elige categoria y selecciona la palabra.
int mostrar_menu_inicio(char *nombre);
void pedir_nombre_jugador(Ranking *jugador);
void mostrar_reglas(void);
int elegir_categoria(void);
#endif