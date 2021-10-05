#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int main(){ 
    int n;
    scanf("%d", &n);
    int* mas = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++){
        mas[i]=i;
    }
    for(int i=0; i<n; i++){
        printf("mas[%d] = %d\n", i, mas[i]);
    }
    free(mas);
}