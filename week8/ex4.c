//Vagif Khalilov BS20-04
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
    struct rusage us; 
    for(int i=0; i<10; i++){
        void* ptr = malloc(524288000);
        memset(ptr, 0, 524288000);
        getrusage(RUSAGE_SELF, &us);
        printf("memory usage: %ld\n", us.ru_maxrss);
        sleep(1);
    }
}
