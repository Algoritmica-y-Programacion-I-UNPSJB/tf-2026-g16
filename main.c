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

void menu(Ranking *jugador);
void esperar_enter();

int main(void)
{
    Ranking jugador;
    int decision_jugador;

    pedir_nombre_jugador(&jugador);
    printf("========================================\n");
    system("clear");

    do
    {
        
        menu(&jugador);

        scanf("%d", &decision_jugador);
        getchar();

        switch (decision_jugador)
        {
            case JUGAR:
                system("clear");
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
                    partida(palabra, &jugador);
                    esperar_enter();
                } 
                else if(jugar == 2)
                {
                    elegir_categoria_azar(palabra);
                    printf("Palabra recibida: '%s'\n", palabra);
                    printf("Longitud: %zu\n", strlen(palabra));
                    partida(palabra, &jugador);
                    esperar_enter();
                }
                else 
                {
                    printf("Opción incorrecta!");
                    esperar_enter();
                }
                break;
            case VER_PUNTAJE:
                system("clear");
                mostrar_ranking();
                esperar_enter();
                break;
            case REGLAS:
                system("clear");
                mostrar_reglas();
                esperar_enter();
                break;
            case SALIR:
                agregar_nuevo_puntaje(&jugador);
                printf("Fin del programa...\n");
                break;
            default:
                printf("Opción inválida...\n");
        }
        system("clear");
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