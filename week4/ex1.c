#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int n=1;
    int v = fork();
    if(v!=0)printf("Hello from parent [%d]\n", v-n);
    else printf("Hello from child [%d]\n", -n);

}
