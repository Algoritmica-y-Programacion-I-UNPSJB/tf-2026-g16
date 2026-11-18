#include  <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ranking.h"
#include "ui_inicio.h"
#include "palabras.h"
#include "partida.h"
#include "puntaje.h"
#include "dispatch_table.h"


/*limpia los salto de línea*/
void esperar_enter(void)
{
    int tecla;

    printf("\nPresione ENTER para volver al menú...");

    while ((tecla = getchar()) != '\n' && tecla != EOF)
    {
        // Vacía el búfer hasta ENTER
    }
}

/**
* @brief Une toda la funcionalidad del juego.
*/
void jugar(Ranking *jugador)
{
    int jugar;
    char palabra[MAX_LONGITUD];
    printf("Seleccione la opción que desea: \n");
    printf("\n1. Elegir categoría.\n");
    printf("2. Categoría al azar.\n");
    scanf("%d", &jugar);
    getchar();

    if(jugar == 1)
    {
        system("clear");
        elegir_categoria(palabra);
        system("clear");
        partida(palabra, jugador);
        esperar_enter();
    } 
    else if(jugar == 2)
    {
        elegir_categoria_azar(palabra);
        printf("Palabra recibida: '%s'\n", palabra);
        printf("Longitud: %zu\n", strlen(palabra));
        partida(palabra, jugador);
        esperar_enter();
    }
    else 
    {
        printf("Opción incorrecta!");
        esperar_enter();
    }
}

void ver_puntaje(Ranking *jugador)
{
    (void)jugador;
    system("clear");
    mostrar_ranking();
    esperar_enter();
}


void reglas(Ranking *jugador)
{
    /**Esto es para mantener la compatibilidad con el puntero a función */
    (void)jugador;
    system("clear");
    mostrar_reglas();
    esperar_enter();
}

void salir(Ranking *jugador)
{
    agregar_nuevo_puntaje(jugador);
    printf("Fin del programa...\n");
}

const decision_usuario TABLA_OPERACION[SALIR + 1] =
{
    [JUGAR] = jugar,
    [VER_PUNTAJE] = ver_puntaje,
    [REGLAS] = reglas,
    [SALIR] = salir
};
