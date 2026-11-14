#include <stdio.h>
#include <stdlib.h>
#include "ranking.h"
#include "ui_inicio.h"
#include "palabras.h"

void menu();
void proceso_de_juego();
void esperar_enter();

int main(void)
{
    int decision_jugador;
    char nombre[NOMBRE_JUGADOR];

    mostrar_menu_inicio(nombre);
    printf("========================================\n");

    do
    {
        
        menu();

        scanf("%d", &decision_jugador);
        getchar();

        switch (decision_jugador)
        {
            case JUGAR:
                system("clear");
                proceso_de_juego();
                printf("\npresiones ENTER para salir...\n");
                esperar_enter();
                break;
            case VER_PUNTAJE:
                system("clear");
                mostrar_ranking();
                printf("\npresiones ENTER para salir...\n");
                esperar_enter();
                break;
            case REGLAS:
                system("clear");
                printf("proceso de muestra de reglas...\n");
                printf("\npresiones ENTER para salir...\n");
                esperar_enter();
                break;
            case SALIR:
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
void menu()
{
    printf("╔════════════════════╗\n");
    printf("║     MENU JUEGO     ║\n");
    printf("╠════════════════════╣\n");
    printf("║  1. Jugar          ║\n");
    printf("║  2. Ver puntaje    ║\n");
    printf("║  3. Reglas         ║\n");
    printf("║  4. salir          ║\n");
    printf("╚════════════════════╝\n");
}

/*Propotipo de interfaz del juego. donde en un principio hay una visión del juego
busco tener una visión general de cómo empezar con el juego
podríamos anotar que funciones necesitamos para darle funcionamiento*/
void proceso_de_juego()
{
    printf("╔═════════════════════════════════════════════════════════╗\n");
    printf("║  NOMBRE_USUARIO                 ________                ║\n");
    printf("║                                |       0                ║\n");
    printf("║                                |      /|\\               ║\n");
    printf("║                                |       |                ║\n");
    printf("║                                |      / \\               ║\n");
    printf("║                                |                        ║\n");
    printf("║                                |                        ║\n");
    printf("║                                |                        ║\n");
    printf("║ letra:                         |    _ _ _ _             ║\n");
    printf("╚═════════════════════════════════════════════════════════╝\n");
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