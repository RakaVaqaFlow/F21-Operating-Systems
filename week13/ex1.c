//Vagif Khalilov BS20-04
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
/*
Banker’s Algorithm from book "Modern Operating Systems" by Andrew Tanenbaum:

    1. Look for a row, R, whose unmet resource needs are all smaller than or
    equal to A. If no such row exists, the system will eventually deadlock
    since no process can run to completion (assuming processes keep all
    resources until they exit).

    2. Assume the process of the chosen row requests all the resources it
    needs (which is guaranteed to be possible) and finishes. Mark that
    process as terminated and add all of its resources to the A vector.

    3. Repeat steps 1 and 2 until either all processes are marked terminated
    (in which case the initial state was safe) or no process is left whose
    resource needs can be met (in which case the system was not safe).

*/

//specify N and M before compiling
const int N = 5;
const int M = 3; 

int main(){
    FILE* input = fopen("input_ok.txt", "r");
    int E[M];
    int A[M];
    int C[N][M];
    int R[N][M];
    int P[N]; 
    for(int i=0; i<N; i++)P[i]=0;

    for(int i=0; i<M; i++){
        fscanf(input, "%d", &E[i]);
    }
    for(int i=0; i<M; i++){
        fscanf(input, "%d", &A[i]);
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            fscanf(input, "%d", &C[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            fscanf(input, "%d", &R[i][j]);
        }
    }

    //3
    while(1){
        //1
        int least_row = -1;
        for(int i=0; i<N; i++){
            if(P[i]==1) continue;
            int check = 1;
            for(int j=0; j<M; j++){
                if(R[i][j]>A[j]){
                    check=0;
                    break;
                }
            }
            if(check){
                least_row = i;
                break;
            }
        }

        if(least_row == -1) {  
            int check = -1;
            for(int i=0; i<N; i++){
                if(P[i]==0){
                    check = i;
                    break;
                }
            }
            if(check==-1){
                printf("OK!\n");
            }
            else{
                printf("process %d deadlock", check);
            }
            return 1; 
        }

        //2
        for(int i=0; i<M; i++){
            A[i]+=C[least_row][i];
        }
        P[least_row] = 1;
    }
}