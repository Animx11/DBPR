#include <stdio.h>
#include <pthread.h>

long var = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* count(){
    while (var < 10000000){
        pthread_mutex_lock(&mutex);
        var++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}


int main(){

    pthread_t threats[2];

    pthread_create(&threats[0], NULL, count, NULL);
    pthread_create(&threats[1], NULL, count, NULL);

    pthread_exit(NULL);

    return 0;
}