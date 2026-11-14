#ifndef PARTIDA_H
#define PARTIDA_H

// Muestra el dibujo del ahorcado según los errores.
void mostrarMuneco(int errores);

// Muestra las letras descubiertas y las ocultas.
void mostrarEstado(const char palabra[], const int descubierta[]);

// Comprueba si se adivinaron todas las letras.
int palabraCompleta(const int descubierta[], int longitud);

// Ejecuta una partida.
// Devuelve 1 si gana, 0 si pierde y -1 si sale.
int partida(const char palabraSecreta[]);

#endif
