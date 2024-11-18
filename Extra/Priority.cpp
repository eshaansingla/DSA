#include <bits/stdc++.h>
using namespace std;
struct Process {
    int pid;       // Process ID
    int arrival;   // Arrival time
    int burst;     // Burst time
    int priority;  // Priority (lower value = higher priority)
    int completion, turnaround, waiting;
};
// Comparator to sort processes by arrival time, then priority
bool compareByArrivalAndPriority(const Process &a, const Process &b) {
    if (a.arrival == b.arrival)
        return a.priority < b.priority; // Lower priority number comes first
    return a.arrival < b.arrival;
}
void calculateTimes(vector<Process> &processes) {
    int currentTime = 0;
    for (auto &process : processes) {
        // If the current time is less than the process arrival time, CPU is idle
        if (currentTime < process.arrival) {
            currentTime = process.arrival;
        }
        // Update completion, turnaround, and waiting times
        process.completion = currentTime + process.burst;
        process.turnaround = process.completion - process.arrival;
        process.waiting = process.turnaround - process.burst;

        currentTime = process.completion; // Update current time
    }
}
void printProcesses(const vector<Process> &processes) {
    cout << "\nPID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";
    for (const auto &process : processes) {
        cout << process.pid << "\t" << process.arrival << "\t" 
             << process.burst << "\t" << process.priority << "\t\t" 
             << process.completion << "\t\t" 
             << process.turnaround << "\t\t" 
             << process.waiting << "\n";
    }
}
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    // Input process details
    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Process " << i + 1 << ":\n";
        processes[i].pid = i + 1;
        cout << "Arrival Time: ";
        cin >> processes[i].arrival;
        cout << "Burst Time: ";
        cin >> processes[i].burst;
        cout << "Priority (lower value = higher priority): ";
        cin >> processes[i].priority;
    }
    // Sort processes by arrival time and then by priority
    sort(processes.begin(), processes.end(), compareByArrivalAndPriority);
    // Calculate completion, turnaround, and waiting times
    calculateTimes(processes);
    // Display the results
    printProcesses(processes);
    return 0;
}
