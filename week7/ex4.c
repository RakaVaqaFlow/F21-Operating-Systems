#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>

void* myRealloc(void* ptr, size_t size){
    if(ptr==NULL) return malloc(size);
    if(size==0) {
        free(ptr);
        return NULL;
    }
    void * newPtr = malloc(size);
	size_t ptrSize = malloc_usable_size(ptr);
	memcpy(newPtr,ptr,ptrSize);
	free(ptr);
	return newPtr;
}
int main(){
	srand(time(NULL));

	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);
    
	int* a1 = myRealloc(NULL, n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		a1[i]=rand()%100;
		printf("%d ",a1[i]);
	}

	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	a1 = myRealloc(a1, n2*sizeof(int));

	for(i=n1; i<n2; i++){
		a1[i]=0;
	}
	
	for(i=0; i<n2;i++){
		printf("%d ",a1[i]);
	}
	printf("\n");
	return 0;
}
