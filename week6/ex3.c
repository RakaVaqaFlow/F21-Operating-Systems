/*

To specify the quantum, you should pass it to command line as a parameter
Example: "./ex3.c 3" - quantum=3

*/
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define INF 1e9

typedef struct process
{
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
} process;

process p[SIZE];
int used[SIZE];
int time[SIZE];
int n = 0;
int quantum = 0;
double averageTurnaroundTime = 0;
double averageWaitingTime = 0;

int cmp(const void *a, const void *b){
    if ((*(process *)a).arrivalTime > (*(process *)b).arrivalTime )
        return 1;
    return 0;
}

int maxVal(int a, int b){ //default max doesn't work correctly on my laptop ¯\_(ツ)_/¯
    return a > b ? a : b;
}

int minVal(int a, int b){
    return a > b ? b : a;
}

void print_info(){

    printf("Quantum = %d\nP#  %5s %5s %5s %5s %5s\n", quantum, "AT", "BT", "CT", "TAT", "WT");
    for (int i = 0; i < n; i++){
        printf("P%-2d %5d %5d %5d %5d %5d\n", i + 1, p[i].arrivalTime, p[i].burstTime, p[i].completionTime, p[i].turnAroundTime, p[i].waitingTime);
    }
    printf("\nAverage Turnaround Time = %f\nAverage Waiting Time = %f", averageTurnaroundTime, averageWaitingTime);
}

void readFromFile(const char *s){
    FILE *inp = fopen(s, "r");
    int at = 0, bt = 0;
    while (fscanf(inp, "%d,%d", &at, &bt) == 2){
        p[n].arrivalTime = at;
        p[n].burstTime = bt;
        n++;
    }
}

int main(int argc, char *argv[]){
    quantum = atoi(argv[1]);
    readFromFile("input.csv");
    
    //Round robin
    qsort(p, n, sizeof(process), cmp);
    for (int i = 0; i < n; i++)
        used[i] = 0, time[i] = p[i].burstTime;
    int currentTime = 0, np = n; // np - number of incomplete processes
    while (np){
        for (int i = 0; i < n; i++){
            if (used[i] == 2) continue;
            else {
                if(currentTime<p[i].arrivalTime && used[i]==0){
                    int j=0;
                    while(j<n && !(used[j]==1)) j++;
                    if(j<i)i=j;
                }
                currentTime = currentTime + minVal(time[i], quantum) + maxVal(p[i].arrivalTime - currentTime, 0);
                if (time[i] <= quantum){
                    used[i] = 2;
                    time[i]=0;
                    p[i].completionTime = currentTime;
                    p[i].turnAroundTime = currentTime - p[i].arrivalTime;
                    p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
                    averageTurnaroundTime += p[i].turnAroundTime;
                    averageWaitingTime += p[i].waitingTime;
                    np--;
                }
                else{
                    used[i] = 1;
                    time[i]=maxVal(time[i]-quantum, 0);
                }
            }
        }
    }
    //---
    averageTurnaroundTime = averageTurnaroundTime / (n * 1.0);
    averageWaitingTime = averageWaitingTime / (n * 1.0);

    print_info();
}
