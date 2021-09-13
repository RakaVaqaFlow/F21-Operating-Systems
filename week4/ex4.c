#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
void split(char in[], char* out[]){
    if(in==NULL) return;
    int i=0;
    char* it = strtok(in, " \n");
    out[0] = it;
    i++;
    while(it!=NULL){
        it = strtok(NULL, " \n");
        out[i] = it;
        i++;
    }
    out[i]=NULL;
}

int main(){
    char line[256];
    char* argv[100];
    while(1){
        fgets(line, 256, stdin);
        if(strcmp(line, "exit\n")==0) break;
        split(line, argv);
        pid_t pid = fork();
        if(!pid) execvp(argv[0], argv);
    } 
}