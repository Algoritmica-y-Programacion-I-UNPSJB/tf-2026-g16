#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "ranking.h"
/*
* Estás constantes definen el tamaño
* nombre del jugador
* y el ranking que tiene
*/
#define NOMBRE_JUGADOR 30
#define TOTAL_RANKING 5
#define COMPARAR_RANKING 4

/**
 * @brief la función leerá el archivo del ranking, y devolverá el total de las personas dentro del ranking.
 *  Se busca llenar un arreglo tipo struct con la cantidad de personas que entran al ranking.
 * @return la cantidad de personas leídas y con ese resultado trabajan otras funciones.
 */ 

int leer_ranking(Ranking *rank, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("¡El archivo no existe");
        return -1;
    }

    size_t leidos = fread(rank, sizeof(Ranking), TOTAL_RANKING, file);
    fclose(file);

    return leidos;
}

/**
* @brief la función guardará el registro luego de ser comparado por otr afunción en el archivo ranking.dat
* @param rank Arreglo evaluado, comparado y ordenado.
* @param filename Documento donde se guardará
* @return En este caso devolveré la cantidad de escritos y leidos del archivo:
     si lee 0, escribe 0, si lee 1, escribe 1,etc.
*/
int guardar_ranking(Ranking *rank, int leidos, const char *filename)
{
    FILE *guardado = fopen(filename, "wb");
    if(guardado == NULL)
    {
        perror("¡Error al abrir el archivo!");
        return 0;
    }

    size_t escritos = fwrite(rank, sizeof(Ranking), leidos, guardado);

    fclose(guardado);

    return escritos == leidos;
}

/**
 * @brief Compara el puntaje de un nuevo jugador con los registros del ranking
 *        y lo incorpora si corresponde.
 * @param rank Arreglo que contiene los registros del ranking actual.
 * @param nuevo_registro Estructura que contiene el nombre y el puntaje del nuevo jugador.
 * @return El espacio nuevo que se regitró si estaba vacío, si no retorna la cantidad que ya estaba
 */

int agregar_nuevo_puntaje(Ranking *rank, Ranking *nuevo_registro)
{
    int leidos = leer_ranking(rank, "ranking.dat");
    bool agregado = false;
    int ultimo_indice;

    /**
     * @param ultimo_indice recibe el valor de la cantidad de leídos.
     */

    if(leidos == 0)
    {
        ultimo_indice = leidos;
    }
    else if(leidos < TOTAL_RANKING)
    {
        ultimo_indice = TOTAL_RANKING - 1;
    }

    /**
     * Función que inserta un nuevo jugador y desplaza el menor puntaje que tiene.
     */
    for(int i = 0; i < leidos; i++)
    {
        if (nuevo_registro->puntaje_jugador > (rank + i)->puntaje_jugador && agregado == false)
        {
            /** 
             * Crea una nueva estructura temporal que recibe el valor de
            */
            for(Ranking *registro = rank + ultimo_indice; registro > rank + i; registro--)
            {
                *registro = *(registro - 1);
            }

            if(agregado == false && leidos < TOTAL_RANKING)
            {
                *(rank + leidos) = *nuevo_registro;
                agregado = true;
            }
        }
    }
    if (agregado == true)
    {
        return guardar_ranking(rank, leidos < TOTAL_RANKING ? leidos + 1 : leidos, "ranking.dat");
    }

    return 0;
}

/**
 * @brief Muestra las 5 posiciones del ranking, indicando
 * los jugadores registrados y las posiciones vacías, si las hay.
 * Se usa un if de guarda, si falla la lectura del archivo, se informa el error
 * y se finaliza la función. 
 */

void mostrar_ranking() 
{
    Ranking rank[TOTAL_RANKING];

    int leidos = leer_ranking(rank, "ranking.dat");
    if (leidos == -1)
    {
        printf("No se pudo leer el ranking.\n");
        return;
    }

    for(int i = 0; i < TOTAL_RANKING; i++)
    {
        if (i < leidos)
        {
            printf("%d. %20s | %d\n", i + 1, rank[i].nombre_jugador, rank[i].puntaje_jugador);
        }
        else
        {
            printf("%d. vacío\n", i + 1);
        }
    }

    return;
}