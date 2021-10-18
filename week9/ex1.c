//Vagif Khalilov BS20-04
/*

Hint, miss and ratio - console output

Other information - file output


ex1_o1.txt - page frame = 10
ex1_o2.txt - page frame = 50
ex1_o3.txt - page frame = 100
*/
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <sys/resource.h>
#include <stdint.h>

typedef struct page{
    int id;
    uint16_t age;
} page;

int N=0;
float miss=0, hit=0;

void ageUpdate(page frames[], int n){
    for(int i=0; i<n; i++){
        frames[i].age >>=1;
    }
}

int findPage(int pageId, page frames[], int n){
    for(int i=0; i<n; i++){
        if(frames[i].id == pageId) return i;
    }
    return -1;
}

void readPage(int pagePos, page frames[]){
    frames[pagePos].age |=1<<(sizeof(uint16_t)*8-1);
}

void addNewPage(int pageId, page frames[], int n){

    //first, let's check if there is space for this page
    int pagePos = -1;
    for(int i=0; i<n; i++){
        if(frames[i].id == -1){
            pagePos = i;
        }
    }

    //if we find a place, just write the page there
    if(pagePos!=-1){
        frames[pagePos].id = pageId;
        readPage(pagePos, frames);
    }
    else { // else, we need to find a page that has not been accessed for a long time
        uint16_t minAge = UINT16_MAX;
        for(int i=0; i<n; i++){
            if(minAge>=frames[i].age){
                minAge = frames[i].age;
                pagePos = i;
            }
        }
        frames[pagePos].id = pageId;
        frames[pagePos].age = 0;
        readPage(pagePos, frames);
    }
}

int main(){
    
    printf("Specify number of page frames:\n");
    scanf("%d", &N);

    page frames[N];
    for (int i=0; i<N; i++){
        frames[i].id = -1;
        frames[i].age = 0;
    }

    FILE* pagesList = fopen("ex1.txt", "r");
    FILE* output = fopen("ex1_o.txt", "w");
    int currentPageId;
    int validReading =0;
    while(!feof(pagesList)){
        //read new page
        validReading = fscanf(pagesList, "%d", &currentPageId);
        if(validReading != 1) continue;

        //print logs
        for(int i=0; i<N; i++){
          fprintf(output, "i = %d  id = %d age = %d\n", i, frames[i].id, frames[i].age);
        }
        fprintf(output, "current page number %d\n\n", currentPageId);
        
        //update age
        ageUpdate(frames, N);

        //work with the page
        int currentPagePos = findPage(currentPageId, frames, N);
        if(currentPagePos == -1){
            miss++;
            addNewPage(currentPageId, frames, N);
        }
        else{
            hit++;
            readPage(currentPagePos, frames);
        }
    }

    float ratio = hit/miss;
    printf("hit=%f miss=%f ratio=%f", hit, miss, ratio);
}
