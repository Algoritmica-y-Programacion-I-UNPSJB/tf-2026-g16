#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "partida.h"
#include "puntaje.h"
#include "ranking.h"
#include "palabras.h"

#define MAX_INTENTOS 6

/* Devuelve 1 si el caracter es una letra del alfabeto ingles. */
static int esLetra(char caracter)
{
    return (caracter >= 'a' && caracter <= 'z') ||
           (caracter >= 'A' && caracter <= 'Z');
}

/* Indica si una letra ya fue ingresada durante la partida. */
static int letraUtilizada(const char letrasUsadas[], int cantidad, char letra)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (letrasUsadas[i] == letra)
            return 1;
    }

    return 0;
}

/* Dibuja el ahorcado de acuerdo con la cantidad de errores. */
void mostrarMuneco(int errores)
{
    printf("\n  +---+\n");
    printf("  |   |\n");

    if (errores >= 1)
        printf("  O   |\n");
    else
        printf("      |\n");

    if (errores >= 4)
        printf(" /|\\  |\n");
    else if (errores == 3)
        printf(" /|   |\n");
    else if (errores == 2)
        printf("  |   |\n");
    else
        printf("      |\n");

    if (errores >= 6)
        printf(" / \\  |\n");
    else if (errores == 5)
        printf(" /    |\n");
    else
        printf("      |\n");

    printf("      |\n");
    printf("=========\n");
}

/* Muestra las letras encontradas y oculta las que faltan adivinar. */
void mostrarEstado(const char palabra[], const int descubierta[])
{
    printf("\nPalabra: ");

    for (int i = 0; palabra[i] != '\0'; i++)
    {
        if (descubierta[i])
            printf("%c ", palabra[i]);
        else
            printf("_ ");
    }

    printf("\n");
}

/* Devuelve 1 cuando todas las posiciones ya fueron descubiertas. */
int palabraCompleta(const int descubierta[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        if (descubierta[i] == 0)
            return 0;
    }

    return 1;
}

/* Ejecuta una partida. Retorna 1 si gana, 0 si pierde y -1 si sale. */
int partida(const char palabraSecreta[], Ranking *puntaje)
{
    int descubierta[MAX_LONGITUD] = {0};
    char letrasUsadas[27];
    int cantidadLetras = 0;
    int longitud;
    int errores = 0;
    int encontrada;
    char letra;
    int caracter;

    if (palabraSecreta == NULL)
    {
        printf("Error: no se recibio una palabra para jugar.\n");
        return -1;
    }

    longitud = (int)strlen(palabraSecreta);

    if (longitud == 0 || longitud >= MAX_LONGITUD)
    {
        printf("Error: la palabra secreta no es valida.\n");
        return -1;
    }

    /* Los espacios y signos se muestran desde el comienzo. */
    for (int i = 0; i < longitud; i++)
    {
        if (!esLetra(palabraSecreta[i]))
            descubierta[i] = 1;
    }

    letrasUsadas[0] = '\0';

    while (errores < MAX_INTENTOS && !palabraCompleta(descubierta, longitud))
    {
        system("clear");
        mostrarMuneco(errores);
        mostrarEstado(palabraSecreta, descubierta);

        printf("\nIntentos restantes: %d\n", MAX_INTENTOS - errores);
        printf("Letras utilizadas: %s\n", letrasUsadas);
        printf("Ingrese una letra (0 para salir): ");

        if (scanf(" %c", &letra) != 1)
            return -1;

        /* Descarta otros caracteres ingresados en la misma linea. */
        while ((caracter = getchar()) != '\n' && caracter != EOF)
        {
            /* No se necesita procesar el resto de la linea. */
        }

        if (letra == '0')
        {
            printf("\nSaliendo de la partida...\n");
            return -1;
        }

        if (!esLetra(letra))
        {
            printf("\nDebe ingresar una sola letra.\n");
            continue;
        }

        letra = (char)tolower((unsigned char)letra);

        if (letraUtilizada(letrasUsadas, cantidadLetras, letra))
        {
            printf("\nYa utilizaste esa letra.\n");
            continue;
        }

        letrasUsadas[cantidadLetras] = letra;
        cantidadLetras++;
        letrasUsadas[cantidadLetras] = '\0';

        encontrada = 0;

        for (int i = 0; i < longitud; i++)
        {
            if (tolower((unsigned char)palabraSecreta[i]) == letra)
            {
                descubierta[i] = 1;
                encontrada = 1;
            }
        }

        if (encontrada)
            printf("\nLa letra esta en la palabra.\n");
        else
        {
            errores++;
            printf("\nLa letra no esta en la palabra.\n");
        }
    }
    system("clear");
    mostrarMuneco(errores);
    mostrarEstado(palabraSecreta, descubierta);

    if (palabraCompleta(descubierta, longitud))
    {
        printf("\nFelicitaciones, ganaste la partida.\n");
        bool gano = true;
        int longitudPalabra;
        longitudPalabra = (int)strlen(palabraSecreta);
        puntaje->puntaje_jugador += calcular_puntaje(gano, errores, longitudPalabra);
        mostrar_resumen(longitudPalabra, gano, errores);
        return 1;
    }

    printf("\nPerdiste la partida.\n");
    printf("La palabra era: %s\n", palabraSecreta);
    return 0;
}
