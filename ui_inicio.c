#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ui_inicio.h"
#include "palabras.h" 

int mostrar_menu_inicio(char *nombre) {
    printf("\n========================================\n");
    printf("          JUEGO DEL AHORCADO\n");
    printf("========================================\n");
    
    printf("Bienvenido! Ingresa tu nombre: ");
    scanf(" %49[^\n]", nombre); 

    printf("\nHola %s! Reglas basicas:\n", nombre);
    printf("- Tenes 6 errores permitidos como maximo.\n");
    printf("- Ingresa una letra por turno.\n");
    printf("- Letras repetidas o invalidas no restan intentos.\n");
    
    struct Categoria categorias[MAX_CATEGORIAS];
    int cant_cats = listar_categorias(categorias, MAX_CATEGORIAS);
    printf("========================================\n");
    system("clear");
    
    printf("\n================ CATEGORIAS ================\n");
    for (int i = 0; i < cant_cats; i++) {
        printf("  %d. %s\n", i + 1, categorias[i].nombre_mostrar);
    }
    
    int opcion = 0;
    do {
        printf("Elegi una categoria (1-%d): ", cant_cats);
        scanf("%d", &opcion);
    } while (opcion < 1 || opcion > cant_cats);

    int indice = opcion - 1; 
    
    printf("\nCargando palabras de %s...\n", categorias[indice].nombre_mostrar);
    
    // Solo cargamos la categoría en la memoria y retornamos
    if (cargar_categoria(categorias[indice].nombre_archivo) == 1) {
        printf("Exito! %d palabras cargadas.\n", cantidad_palabras());
        printf("Todo listo. A jugar!\n");
        printf("========================================\n\n");
        return 1; 
    }
    
    printf("\nERROR CRITICO: No se encontro el archivo '%s'.\n", categorias[indice].nombre_archivo);
    return 0; 
}