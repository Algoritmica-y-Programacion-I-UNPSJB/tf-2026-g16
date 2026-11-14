#ifndef RANKING_H
#define RANKING_H

#define NOMBRE_JUGADOR 30
#define TOTAL_RANKING 5

//menu para las opciones del menú
typedef enum
{
    JUGAR = 1,
    VER_PUNTAJE,
    REGLAS,
    SALIR
} Decision_menu;

typedef struct 
{
    char nombre_jugador[NOMBRE_JUGADOR];
    int puntaje_jugador;
} Ranking;

int leer_ranking(Ranking *rank, const char *filename);
int agregar_nuevo_puntaje(Ranking *rank, Ranking *nuevo_registro);
int guardar_ranking(Ranking *rank, int leidos, const char *filename);
void mostrar_ranking();


#endif