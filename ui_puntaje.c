#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "puntaje.h"

void mostrar_resumen(int largo_palabra, bool gano, int errores) {
    int puntos = calcular_puntaje(gano, errores, largo_palabra);
    printf("\n=== RESUMEN ===\n");
    printf("Cantidad de letras: %d\n", largo_palabra);
    printf("Resultado: %s\n", gano ? "¡Ganaste!" : "Perdiste");
    printf("Errores: %d\n", errores);
    printf("Puntaje: %d\n", puntos);
}

int calcular_puntaje(bool gano, int errores, int largo_palabra) {
    if (!gano) return 0;

    int puntos = largo_palabra * 10;   // base por largo
    puntos -= errores * 5;             // penalización por error
    if (errores == 0) puntos += 20;    // bonus partida perfecta

    return puntos < 0 ? 0 : puntos;
}
