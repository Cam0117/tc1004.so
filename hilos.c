#include <pthread.h> // Librería para el hilo
#include <stdio.h>   // 

int saldo;
int cuenta;

void *holaHilo(){
    cuenta++;
    printf("HILO1>> Hola desde un hilo, cuenta: %d\n",cuenta);
    pthread_exit(NULL);
}

void *incrementoSaldo(){
    saldo+=100;
    printf("HILO2>> El saldo actual es: %d\n", saldo);
    pthread_exit(NULL);
}

int main(){
    pthread_t t;
    pthread_t u;
    for (int i=0; i<100; i++){
        pthread_create(&t,NULL,holaHilo,NULL);
        pthread_create(&u,NULL,incrementoSaldo,NULL);
    }
    pthread_exit(NULL);
}