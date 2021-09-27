#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct process{
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
} process;

process p[SIZE];
int n = 0;
double averageTurnaroundTime = 0;
double averageWaitingTime = 0;

int cmp(const void *a, const void *b){
    if ((*(process *)a).arrivalTime > (*(process *)b).arrivalTime)
        return 1;
    return 0;
}

int maxVal(int a, int b){ //default max doesn't work correctly on my laptop ¯\_(ツ)_/¯
    return a > b ? a : b;
}

void print_info(){

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

    //FCFS
    qsort(p, n, sizeof(process), cmp);
    int currentTime = 0;
    for (int i = 0; i < n; i++){
        currentTime = currentTime + p[i].burstTime + maxVal(p[i].arrivalTime - currentTime, 0);
        p[i].completionTime = currentTime;
        p[i].turnAroundTime = currentTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;

        averageTurnaroundTime += p[i].turnAroundTime;
        averageWaitingTime += p[i].waitingTime;
    }
    //--
    averageTurnaroundTime = averageTurnaroundTime / (n * 1.0);
    averageWaitingTime = averageWaitingTime / (n * 1.0);

    print_info();
}