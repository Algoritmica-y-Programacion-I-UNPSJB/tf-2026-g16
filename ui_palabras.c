#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "palabras.h"

static char banco_palabras[MAX_PALABRAS][MAX_LONGITUD];
static int total_palabras = 0;

int listar_categorias(struct Categoria lista[], int max_cats) {
    if (max_cats < 3) return 0; 

    strcpy(lista[0].nombre_mostrar, "Animales");
    strcpy(lista[0].nombre_archivo, "animales.txt");

    strcpy(lista[1].nombre_mostrar, "Deportes");
    strcpy(lista[1].nombre_archivo, "deportes.txt");

    strcpy(lista[2].nombre_mostrar, "Paises");
    strcpy(lista[2].nombre_archivo, "paises.txt");

    return 3;
}

int cargar_categoria(const char *nombre_archivo) {
    FILE *archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        return 0; 
    }

    total_palabras = 0;
    // CORRECCIÓN CLAVE: " %29[^\n]" lee la línea completa incluyendo espacios
    while (total_palabras < MAX_PALABRAS && fscanf(archivo, " %29[^\n]", banco_palabras[total_palabras]) == 1) {
        total_palabras++;
    }

    fclose(archivo);
    return 1;
}

int cantidad_palabras() {
    return total_palabras;
}

int elegir_palabra(char *destino) {
    if (total_palabras == 0) return 0; 
    
    int indice_azar = rand() % total_palabras;
    strcpy(destino, banco_palabras[indice_azar]);
    return 1;
}

int elegir_categoria_azar(char *palabra)
{
    struct Categoria categorias[MAX_CATEGORIAS];

    int cantidad = listar_categorias(categorias, MAX_CATEGORIAS);

    if (cantidad == 0)
        return 0;

    int indice = rand() % cantidad;

    if (!cargar_categoria(categorias[indice].nombre_archivo))
        return 0;

    return elegir_palabra(palabra);
}