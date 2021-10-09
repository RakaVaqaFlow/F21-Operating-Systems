//Vagif Khalilov BS20-04
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <unistd.h>


/*
When we run the program in the background and execute vmstat 1, after a few times we may notice non-zero 
si (amount of memory swapped in from disk per second) and so (amount of memory swapped to disk per second) values. 
It means that there is a swapping happens
*/
int main(){ 
    for(int i=0; i<10; i++){
        // let's allocate 500mb in each iteration instead of 10mb
        void* ptr = malloc(524288000);
        memset(ptr, 0, 524288000);
        sleep(1);
    }
}
