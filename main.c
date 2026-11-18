#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "ranking.h"
#include "ui_inicio.h"
#include "palabras.h"
#include "partida.h"
#include "puntaje.h"
#include "dispatch_table.h"

void menu(Ranking *jugador);

int main(void)
{
    Ranking jugador = {0};
    int decision_jugador;

    pedir_nombre_jugador(&jugador);
    printf("========================================\n");
    system("clear");

    do
    {
        
        menu(&jugador);

        scanf("%d", &decision_jugador);
        getchar();

        if(decision_jugador >= JUGAR && decision_jugador <= SALIR)
        {
            TABLA_OPERACION[decision_jugador](&jugador);
        }
        else 
        {
            printf("¡Opción inválida!\n");
            esperar_enter();
        }

        
    } while (decision_jugador != SALIR);

    return 0;
}

/*Esta funcion va a devolver el menu principal de la entrada del juego*/
void menu(Ranking *jugador)
{
    printf("╔════════════════════╗\n");
    printf("║     MENU JUEGO     ║\n");
    printf("╠════════════════════╣\n");
    printf("║  1. Jugar          ║\n");
    printf("║  2. Ver puntaje    ║\n");
    printf("║  3. Reglas         ║\n");
    printf("║  4. salir          ║\n");
    printf("╚════════════════════╝\n");

    printf("\nNombre: %s\n", jugador->nombre_jugador);
    printf("Puntaje actual: %d\n", jugador->puntaje_jugador);
}