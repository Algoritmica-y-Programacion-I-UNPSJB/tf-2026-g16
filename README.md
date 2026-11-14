# Ahorcado en C - Trabajo Integrador Final

Este proyecto es un desarrollo en lenguaje C del clásico juego "El Ahorcado", realizado como Trabajo Integrador Final para la materia Algorítmica y Programación I (2026).

## Integrantes y aportes

El equipo está conformado por 4 integrantes. Las responsabilidades se dividieron de manera equitativa:

# (estos son posibles roles, es más un ejemplo de como podriamos poner o asignar los roles en lo que deriva la codificacion por cada uno despues)

*   Nacho Sanzone: Arquitectura general y bucle principal del juego. Desarrollo de las funciones de lógica (validación de letras y control de intentos). (Aprox. [X] horas).
*   Nicolás Ullua: Diseño de la capa de presentación (interfaz de consola), menú interactivo, saludo al jugador y muestra del ranking final. (Aprox. [X] horas).
*   Lautaro *****: Manejo de datos y estado. Implementación de las estructuras (structs) y carga del banco de palabras. (Aprox. [X] horas).
*   Alex ****: Testing general, manejo de casos límite (letras repetidas, caracteres inválidos) y documentación. (Aprox. [X] horas).

## Reglas y controles del juego

Objetivo: Adivinar la palabra oculta antes de cometer 6 errores (completar la figura del ahorcado).

# lo mismo con lo de los roles, acá le pedi mas a gemini que se encargue de como puede ir mecanizando el asunto

Reglas:
1. Al iniciar, el programa solicita el nombre del jugador y presenta las reglas básicas.
2. En cada turno, el jugador debe ingresar una sola letra.
3. Si la letra pertenece a la palabra oculta, se revela su posición.
4. Si la letra es incorrecta, se descuenta un intento y se dibuja una parte del ahorcado.
5. El juego evita penalizar por ingresar la misma letra dos veces (avisa al jugador).
6. **Fin de la partida:** El juego termina cuando se adivina la palabra o se acaban los intentos. Al finalizar, se muestra un resumen con el puntaje obtenido y espera a que el usuario presione una tecla para salir.

Controles:
Se utiliza el teclado estándar. Se ingresa una letra (mayúscula o minúscula) y se presiona `ENTER`.

## Compilación y ejecución

Para compilar y ejecutar el juego desde la terminal (usando GCC), utilizar los siguientes comandos:

```bash
# 1. Compilar el código fuente
gcc -o ahorcado main.c logica.c presentacion.c

# 2. Ejecutar el juego
./ahorcado
```

## Organización de datos y funciones

Respetando la guía de diseño de la cátedra, el programa divide sus responsabilidades en tres capas fundamentales para no mezclar la presentación con las reglas del juego:

### 1. Datos / Estado
Utilizamos estructuras (`struct`) para mantener el estado actual de la partida.
*   `EstadoPartida`: Guarda la palabra secreta, la palabra parcialmente adivinada, el número de intentos restantes y el puntaje actual.

### 2. Lógica del juego
Maneja las reglas sin interactuar directamente con la pantalla (no hace `printf` ni `scanf`).
*   `inicializar_partida()`: Selecciona una palabra al azar y resetea los intentos.
*   `verificar_letra(char letra)`: Comprueba si la letra ingresada es válida y si pertenece a la palabra. Actualiza el estado y devuelve `1` (acierto), `0` (error) o `-1` (letra ya usada).
*   `partida_terminada()`: Comprueba si los intentos llegaron a 0 o si ya no quedan letras por adivinar.

### 3. Entrada y presentación
Se encarga exclusivamente de interactuar con el usuario.
*   `mostrar_menu()`: Pide el nombre, saluda y muestra las instrucciones.
*   `dibujar_ahorcado(int intentos)`: Imprime el tablero y la figura en consola basándose en el estado actual.
*   `mostrar_resultado()`: Imprime el mensaje de victoria o derrota y el ranking, esperando una tecla para cerrar.

## Interfaz gráfica (Opcional)
Nota: Este proyecto fue desarrollado con una interfaz 100% de consola mediante texto, cumpliendo con los requisitos base de la cátedra sin uso de generación por IA.*