#include <stdio.h>
#include <pthread.h>

long var = 0;

void* count(){
    while (var < 10000000){
        var++;
    }
    return NULL;
}


int main(){

    pthread_t threats[1];

    pthread_create(&threats[0], NULL, count, NULL);

    pthread_exit(NULL);

    return 0;
}