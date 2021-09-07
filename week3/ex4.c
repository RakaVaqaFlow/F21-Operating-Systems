#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t = *a;
    *a=*b; 
    *b=t;
}

void quicksort(int a[], int l, int r){
    if(l>=r) return;
    int mid = (r+l)/2;
    int i=l, j=r;
    while(i<=j){
        while(a[i]<a[mid])i++;
        while(a[j]>a[mid])j--;
        if(i>=j)break;
        swap(&a[i], &a[j]);
        i++;
        j--;
    }
    quicksort(a, l, j);
    quicksort(a, j+1, r);
}

void print_array(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
}

int main(){
    int n=10;
    int a[] = {10, -9, 8, -7, 5, 5, 0, 78, 999, 1};
    printf("Your array before  quicksort:\n");
    print_array(a, n);
    printf("Your array after quicksort:\n");
    quicksort(a, 0, n-1);
    print_array(a, n);
    return 0;
}