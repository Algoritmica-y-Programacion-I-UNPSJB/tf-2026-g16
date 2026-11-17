#ifndef PARTIDA_H
#define PARTIDA_H

/* Muestra el dibujo del ahorcado segun la cantidad de errores. */
void mostrarMuneco(int errores);

/* Muestra las letras descubiertas y oculta las restantes. */
void mostrarEstado(const char palabra[], const int descubierta[]);

/* Devuelve 1 si la palabra esta completa y 0 si todavia faltan letras. */
int palabraCompleta(const int descubierta[], int longitud);

/* Ejecuta una partida: 1 si gana, 0 si pierde y -1 si el jugador sale. */
int partida(const char palabraSecreta[]);

#endif
