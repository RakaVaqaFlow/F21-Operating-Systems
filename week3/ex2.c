#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void swap(int *a, int* b){
    int t=*a;
    *a=*b;
    *b=t;
}

void bubble_sort(int a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>a[j]) swap(&a[i], &a[j]);
        }
    }
}

void print_array(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
}

int main(){
    int n=10;
    int a[] = {10, -9, 8, -7, 5, 5, 0, 78, 999, 1};
    printf("Your array before bubble sort:\n");
    print_array(a, n);
    printf("Your array after bubble sort:\n");
    bubble_sort(a, n);
    print_array(a, n);
    return 0;
}