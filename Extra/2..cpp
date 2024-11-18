#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int remainingTime; // For SJF Pre-emptive
};

void calculateAverageWaitingTime(const vector<Process>& processes) {
    double totalWaitingTime = 0;
    for (const auto& process : processes) {
        totalWaitingTime += process.waitingTime;
    }
    cout << "Average Waiting Time: " << fixed << setprecision(2) 
         << totalWaitingTime / processes.size() << " ms\n";
}

void printProcesses(const vector<Process>& processes) {
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\n";
    for (const auto& process : processes) {
        cout << "P" << process.id << "\t" << process.arrivalTime 
             << "\t\t" << process.burstTime 
             << "\t\t" << process.waitingTime << "\n";
    }
}

void fcfs(vector<Process> processes) {
    cout << "\nFCFS Scheduling:\n";

    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    for (auto& process : processes) {
        if (currentTime < process.arrivalTime) {
            currentTime = process.arrivalTime;
        }
        process.waitingTime = currentTime - process.arrivalTime;
        currentTime += process.burstTime;
    }

    printProcesses(processes);
    calculateAverageWaitingTime(processes);
}

void sjfNonPreemptive(vector<Process> processes) {
    cout << "\nSJF Non-Preemptive Scheduling:\n";

    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    vector<Process> readyQueue;
    vector<Process> completed;

    while (!processes.empty() || !readyQueue.empty()) {
        while (!processes.empty() && processes.front().arrivalTime <= currentTime) {
            readyQueue.push_back(processes.front());
            processes.erase(processes.begin());
        }

        if (!readyQueue.empty()) {
            sort(readyQueue.begin(), readyQueue.end(), [](const Process& a, const Process& b) {
                return a.burstTime < b.burstTime;
            });

            Process current = readyQueue.front();
            readyQueue.erase(readyQueue.begin());

            current.waitingTime = currentTime - current.arrivalTime;
            currentTime += current.burstTime;
            completed.push_back(current);
        } else {
            currentTime++;
        }
    }

    printProcesses(completed);
    calculateAverageWaitingTime(completed);
}

void sjfPreemptive(vector<Process> processes) {
    cout << "\nSJF Preemptive Scheduling:\n";

    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0, completed = 0;
    vector<Process> completedProcesses;

    while (completed < processes.size()) {
        int shortestIndex = -1;
        for (int i = 0; i < processes.size(); i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0) {
                if (shortestIndex == -1 || processes[i].remainingTime < processes[shortestIndex].remainingTime) {
                    shortestIndex = i;
                }
            }
        }

        if (shortestIndex != -1) {
            processes[shortestIndex].remainingTime--;
            currentTime++;

            if (processes[shortestIndex].remainingTime == 0) {
                processes[shortestIndex].waitingTime = currentTime - processes[shortestIndex].arrivalTime - processes[shortestIndex].burstTime;
                completed++;
                completedProcesses.push_back(processes[shortestIndex]);
            }
        } else {
            currentTime++;
        }
    }

    printProcesses(completedProcesses);
    calculateAverageWaitingTime(completedProcesses);
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter arrival time for process P" << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter burst time for process P" << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0;
    }

    cout << "\nSelect Scheduling Algorithm:\n";
    cout << "1. FCFS\n";
    cout << "2. SJF Non-Preemptive\n";
    cout << "3. SJF Preemptive\n";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            fcfs(processes);
            break;
        case 2:
            sjfNonPreemptive(processes);
            break;
        case 3:
            sjfPreemptive(processes);
            break;
        default:
            cout << "Invalid choice!\n";
            break;
    }

    return 0;
}
