#include<stdio.h>
/*
 Program to find the shortest job first and calculate the avarage time
*/

void swap(int *a, int *b) {
  int val = *a;
  *a = *b;
  *b = val;
}

void findWaitingTime(int processIds[], int n, int burstTime[], int waitingTime[]) {
   waitingTime[0]=0;
   int i=1;
   for(;i<n;i++) {
     waitingTime[i]=burstTime[i-1]+waitingTime[i-1];
   }
}

void findTurnAroundTime(int processIds[], int n, int burstTime[], int waitingTime[], int turnAroundTime[]) {
   int i=0;
   for(i=0;i<n;i++) {
      turnAroundTime[i]=burstTime[i]+waitingTime[i];
   }
}
void findAvgTime(int processIds[], int n, int burstTime[]) {
   int avgTime = 0;
   int waitingTime[n];
   int turnAroundTime[n];

   findWaitingTime(processIds, 	n, burstTime,waitingTime);
   findTurnAroundTime(processIds,n,burstTime,waitingTime,turnAroundTime);

   int i=0;

   int totalWaitTime = 0;
   int totalTurnAroundTime = 0;
   printf("Processes  Burst time  Waiting time      time\n");
   for(;i<n;i++) {
      totalWaitTime+=waitingTime[i];
      totalTurnAroundTime +=turnAroundTime[i];
      printf("%d\t %d\t %d\t  %d\n",processIds[i],burstTime[i],waitingTime[i],turnAroundTime[i]);
   }
   avgTime = totalTurnAroundTime/totalWaitTime;   
   printf("\n Avarage Time : %d",avgTime);
}
int main() {
   int processIds[]={1,2,3,4};
   int burstTime[]={3,2,1,2};
   int n = 4;

   // finding the shortest job in the given list
   int i=0;
   for(i=0; i<4;i++) {
     int j=i+1;
     for(;j<4;j++) {
        if(burstTime[i]>burstTime[j]) {
           swap(&processIds[i],&processIds[j]);
           swap(&burstTime[i],&burstTime[j]);
        }
     }
  }
  
  findAvgTime(processIds,4,burstTime);
  return 0;
}
   
   
