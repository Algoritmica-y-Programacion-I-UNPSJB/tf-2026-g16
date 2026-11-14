#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "partida.h"

#define MAX_LETRAS 50
#define MAX_INTENTOS 6

// Muestra el muñeco del ahorcado.
void mostrarMuneco(int errores)
{
    printf("\n");
    printf("  +---+\n");
    printf("  |   |\n");

    if (errores >= 1)
        printf("  O   |\n");
    else
        printf("      |\n");

    if (errores == 2)
        printf("  |   |\n");
    else if (errores == 3)
        printf(" /|   |\n");
    else if (errores >= 4)
        printf(" /|\\  |\n");
    else
        printf("      |\n");

    if (errores == 5)
        printf(" /    |\n");
    else if (errores >= 6)
        printf(" / \\  |\n");
    else
        printf("      |\n");

    printf("      |\n");
    printf("=========\n");
}

// Muestra las letras descubiertas y las ocultas.
void mostrarEstado(const char palabra[], const int descubierta[])
{
    int i;

    printf("\nPalabra: ");

    for (i = 0; palabra[i] != '\0'; i++)
    {
        if (descubierta[i])
            printf("%c ", palabra[i]);
        else
            printf("_ ");
    }

    printf("\n");
}

// Comprueba si se adivinaron todas las letras.
int palabraCompleta(const int descubierta[], int longitud)
{
    int i;

    for (i = 0; i < longitud; i++)
    {
        if (!descubierta[i])
            return 0;
    }

    return 1;
}

// Ejecuta una partida.
int partida(const char palabraSecreta[])
{
    int descubierta[MAX_LETRAS] = {0};
    char letrasUsadas[27] = "";
    char letra;
    int longitud;
    int errores = 0;
    int i;
    int encontrada;

    longitud = (int)strlen(palabraSecreta);

    // Evita trabajar con palabras demasiado largas o vacías.
    if (longitud == 0 || longitud >= MAX_LETRAS)
    {
        printf("Error: la palabra secreta no es válida.\n");
        return -1;
    }

    // Bucle principal de la partida.
    while (errores < MAX_INTENTOS &&
           !palabraCompleta(descubierta, longitud))
    {
        mostrarMuneco(errores);
        mostrarEstado(palabraSecreta, descubierta);

        printf("\nIntentos restantes: %d\n", MAX_INTENTOS - errores);
        printf("Letras utilizadas: %s\n", letrasUsadas);
        printf("Ingrese una letra (0 para salir): ");

        if (scanf(" %c", &letra) != 1)
            return -1;

        letra = (char)tolower((unsigned char)letra);

        // Permite salir de la partida.
        if (letra == '0')
        {
            printf("\nSaliendo de la partida...\n");
            return -1;
        }

        // Comprueba que sea una letra.
        if (letra < 'a' || letra > 'z')
        {
            printf("\nIngrese una letra válida.\n");
            continue;
        }

        // Comprueba si la letra ya fue utilizada.
        if (strchr(letrasUsadas, letra) != NULL)
        {
            printf("\nYa utilizaste esa letra.\n");
            continue;
        }

        // Guarda la letra utilizada.
        {
            int cantidad = (int)strlen(letrasUsadas);
            letrasUsadas[cantidad] = letra;
            letrasUsadas[cantidad + 1] = '\0';
        }

        encontrada = 0;

        // Busca la letra en la palabra secreta.
        for (i = 0; i < longitud; i++)
        {
            if (tolower((unsigned char)palabraSecreta[i]) == letra)
            {
                descubierta[i] = 1;
                encontrada = 1;
            }
        }

        // Si no se encontró, pierde un intento.
        if (!encontrada)
        {
            errores++;
            printf("\nLa letra no está en la palabra.\n");
        }
        else
        {
            printf("\n¡Bien! La letra está en la palabra.\n");
        }
    }

    // Muestra el resultado final.
    mostrarMuneco(errores);
    mostrarEstado(palabraSecreta, descubierta);

    if (palabraCompleta(descubierta, longitud))
    {
        printf("\n¡FELICIDADES! Ganaste la partida.\n");
        return 1;
    }
    else
    {
        printf("\nPerdiste la partida.\n");
        printf("La palabra era: %s\n", palabraSecreta);
        return 0;
    }
}
