#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define INF 1e9

typedef struct process{
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
} process;

process p[SIZE];
int used[SIZE];
int n = 0;
double averageTurnaroundTime = 0;
double averageWaitingTime = 0;

int cmp(const void *a, const void *b){
    if ((*(process *)a).arrivalTime > (*(process *)b).arrivalTime 
    || ((*(process *)a).arrivalTime == (*(process *)b).arrivalTime && (*(process *)a).burstTime > (*(process *)b).burstTime)) return 1;
    return 0;
}

int maxVal(int a, int b){ //default max doesn't work correctly on my laptop ¯\_(ツ)_/¯
    return a > b ? a : b;
}

void print_info() {
    
    printf("P#  %5s %5s %5s %5s %5s\n", "AT", "BT", "CT", "TAT", "WT");
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

int main(){
    readFromFile("input.csv");

    //SJN
    for (int i = 0; i < n; i++)
        used[i] = 0;
    qsort(p, n, sizeof(process), cmp);
    int currentTime = 0, it = -1, minBT = INF;
    for (int i = 0; i < n; i++){
        it = -1, minBT = INF;
        for (int j = 0; j < n; j++){
            if (!used[j] && currentTime >= p[j].arrivalTime && minBT > p[j].burstTime){
                it = j;
                minBT = p[it].burstTime;
            }
        }
        if (it = -1){
            it = 0;
            while (used[it]) it++;
        }
        used[it] = 1;
        currentTime = currentTime + p[it].burstTime + maxVal(p[it].arrivalTime - currentTime, 0);
        p[it].completionTime = currentTime;
        p[it].turnAroundTime = currentTime - p[it].arrivalTime;
        p[it].waitingTime = p[it].turnAroundTime - p[it].burstTime;

        averageTurnaroundTime += p[it].turnAroundTime;
        averageWaitingTime += p[it].waitingTime;
    }
    //---
    averageTurnaroundTime = averageTurnaroundTime / (n * 1.0);
    averageWaitingTime = averageWaitingTime / (n * 1.0);

    print_info();
}
