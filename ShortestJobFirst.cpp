#include<iostream>
/*
Shortest Job First Algorithm
This program implements the Shortest Job First (SJF) scheduling algorithm.
It calculates the waiting time and turnaround time for each process based on their burst times.
*/
using namespace std;
void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0; // Waiting time for first process is 0

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}
void findavgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    cout << "Processes " << " Burst time " << " Waiting time " << "      time\n";
    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << " " << processes[i] << "\t\t" << bt[i] << "\t " << wt[i] << "\t\t " << tat[i] << endl;
    }
    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turnaround time = " << (float)total_tat / (float)n;
}
int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {6, 8, 7};
    // Sort processes based on burst time (SJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burst_time[i] > burst_time[j]) {
                swap(burst_time[i], burst_time[j]);
                swap(processes[i], processes[j]);
            }
        }
    }
        (processes, n, burst_time);
    return 0;
}   
