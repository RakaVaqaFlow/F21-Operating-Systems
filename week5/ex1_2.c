#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


void *someFun(void *var){
    static int num = 0;
    sleep(2);
    printf("Hello from thread %d\n", num);
    num++;
    return NULL;
} 

int main(){
    int n=5;
    pthread_t thread_id;
    for(int i=0; i<n; i++){
        printf("Creating thread %d\n", i);
        pthread_create(&thread_id, NULL, someFun, NULL);
        printf("Terminating of thread %d\n", i);
        pthread_join(thread_id, NULL);
    }
    exit(0); 
}