#include  <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ranking.h"

typedef void(*decision_usuario)(int *decision);

const decision_usuario TABLA_OPERACION[SALIR] =
{
    [VER_PUNTAJE] = mostrar_ranking
};

