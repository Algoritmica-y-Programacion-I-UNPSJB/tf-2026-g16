#ifndef PALABRAS_H
#define PALABRAS_H

#define MAX_PALABRAS 100
#define MAX_LONGITUD 30
#define MAX_CATEGORIAS 3 

struct Categoria {
    char nombre_mostrar[30];
    char nombre_archivo[30];
};

// Firma corregida para que el compilador no tire error
int listar_categorias(struct Categoria lista[], int max_cats);
int cargar_categoria(const char *nombre_archivo);
int cantidad_palabras();
int elegir_palabra(char *destino);

#endif