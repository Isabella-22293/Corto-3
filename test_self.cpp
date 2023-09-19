/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3086 - Programacion de Microprocesadores
Modificado por: Kimberly Barrera
Fecha: 08/11/2019
Mod:   09/12/2023

test_self.cpp
Hilo realiza rutina para impresión de 
thread id 
---------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Función que imprime el identificador de un hilo
void *PrintID(void *threadid) {
    //pthread_t tid;
    //tid = (pthread_t)threadid;
    
    // Imprime el identificador del hilo actual usando pthread_self()
    printf("Subrutina - Thread ID: %ld", pthread_self());
    printf("\n");
    
    pthread_exit(NULL);
    return NULL;
}

int main () {
    pthread_t threads; // Variable para almacenar el identificador del hilo creado
    int rc;
   
    printf("\n--- MAIN() : CREANDO UN NUEVO HILO ---");
    
    // Crea un nuevo hilo que ejecutará la función PrintID sin argumentos
    rc = pthread_create(&threads, NULL, PrintID, NULL);
    
    // Imprime el identificador del hilo principal
    printf("\nMain - Thread ID: %ld\n", pthread_self());
    
    // Espera a que el hilo creado termine su ejecución
    pthread_join(threads, NULL);
    
    pthread_exit(NULL); // Finaliza el hilo principal
    
    return 0;
}
