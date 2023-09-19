/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3056 - Programacion de Microprocesadores
Modificado por: Kimberly Barrera
Fecha: 08/11/2019
Mod:   09/12/23

argumentos1.cpp
Comparte a subrutina argumentos en es-
tructura con elementos de múltpiple 
tipo, hacia el thread creado
---------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define num_th 100 // Número de hilos a crear

// Define una estructura con los parámetros que se pasarán a los hilos
struct parameters {
    int id;      // Identificador del hilo
    float val1;  // Valor 1
    float val2;  // Valor 2
};

// Función que realiza un cálculo simple y muestra el resultado
void *calculate(void *arg) {
    parameters *ps;
    ps = (parameters *)arg;
    float res;

    // Realiza el cálculo (val1 * val2)
    res = ps->val1 * ps->val2;
    
    // Imprime el identificador del hilo y el resultado del cálculo
    printf("Thread %d resultado %f\n", ps->id, res);

    // Finaliza el hilo
    pthread_exit(NULL);
}

int main() {
    pthread_t thread[num_th]; // Arreglo para almacenar los identificadores de los hilos
    int i;
    parameters p;

    // Bucle que crea y une hilos en paralelo
    for (i = 1; i < num_th; i++) {
        p.id = i;           // Asigna un identificador único al hilo
        p.val1 = i;         // Asigna un valor a val1 (depende de la iteración)
        p.val2 = i - 1;     // Asigna un valor a val2 (depende de la iteración)

        // Crea un nuevo hilo que ejecuta la función calculate con los argumentos p
        pthread_create(&thread[i], NULL, calculate, (void *)&p);
        
        // Espera a que el hilo recién creado termine su ejecución antes de continuar
        pthread_join(thread[i], NULL);
    }

    printf("\n--- Fin ---\n"); // Mensaje de finalización del programa

    return 0;
}
