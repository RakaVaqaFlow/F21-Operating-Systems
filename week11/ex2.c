//Vagif Khalilov BS20-04
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <sys/resource.h>
#include <stdint.h>
#include <dirent.h>

int main(){
    DIR *dir; 
    struct dirent *ent;
    if ((dir = opendir ("/")) == NULL)  return 0;
    while (ent = readdir(dir)) {
    	printf("%s\n", (*ent).d_name);
    }
    closedir(dir);
    return 0;
}
