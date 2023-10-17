#include <pthread.h>
#include <stdio.h>

int saldo;
int cuenta;

void *holaHilo(void *thid){
    printf("Hola desde un hilo, %d\n",*((int *)thid));
    pthread_exit(NULL);
}

//void *incrementoSaldo(){
    //saldo+=100;
    //printf("El saldo actual es: %d\n", saldo);
    //pthread_exit(NULL);
//}

int main(){
    pthread_t t;
    saldo=0;
    int thid=0;
    for(int i=0; i<100; i++){
        pthread_create(&t,NULL,holaHilo,&thid);
        thid++;
    }
    pthread_exit(NULL);
}