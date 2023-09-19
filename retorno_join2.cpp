/*---------------------------------------
UNIVERSIDAD DEL VALLE DE GUATEMALA
CC3086 - Programacion de Microprocesadores
Modificado por: Kimberly Barrera

Fecha:   09/12/2023

retorno.cpp
Comparte desde subrutina argumento puntero
de tipo void, por medio de return.
---------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
// declaración del prototipo para la función que se ejecuta en otro hilo

void *calculos(void* argument){
//Declarar tipo de dato
	int input, output;
	
	input = (int)(intptr_t) argument;
//Realizar operaciones 	
	output = input*2;
//Retornar puntero tipo void
	return (void*)(intptr_t) output;
}
int main(){

	printf("\n\n");
	pthread_t thread_id;
	pthread_attr_t attr;
	
	pthread_attr_init (&attr);
//Declarar atributos de hilos joinable
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
//Declarar el puntero void que permitirá pasar el parametro p,/cada hilo
	void *exit_value;
	unsigned int result = 1;
	
	for(int i = 0; i < 10; i++){
		pthread_create(&thread_id, &attr, calculos, (void*) (intptr_t) i);

	}
	
	for(int i = 0; i < 10; i++){
//Dirección donde guardará valor retornado desde la subrutina al main
		pthread_join(thread_id, &exit_value);
//Usar el valor retornado en el main
		int result =(int)(intptr_t)exit_value;
		printf("Resultado multiplicación es: %d\n", result);
	}
	
	pthread_attr_destroy(&attr);
	pthread_exit(NULL);
	return 0;
	
}


