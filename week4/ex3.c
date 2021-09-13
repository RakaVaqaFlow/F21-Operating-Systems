#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* line = malloc(sizeof(char)*256);
    while(strcmp(line, "exit\n")){
        fgets(line, 256, stdin);
        system(line);
    }
}