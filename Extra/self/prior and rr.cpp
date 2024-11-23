#include <bits/stdc++.h>

using namespace std;

struct Process {
    int pid;        // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int priority;   // Priority (for priority scheduling)
    int waiting;    // Waiting time
    int turnaround; // Turnaround time
};

void calculateAverageTime(vector<Process> &processes) {
    double totalWaitingTime = 0;
    for (const auto &p : processes) {
        totalWaitingTime += p.waiting;
    }
    cout << "Average Waiting Time: " << fixed << setprecision(2) << totalWaitingTime / processes.size() << "\n";
}

void roundRobin(vector<Process> &processes, int quantum) {
    int time = 0, n = processes.size();
    vector<int> remainingBurst(n);
    for (int i = 0; i < n; i++) remainingBurst[i] = processes[i].burst;

    queue<int> q;
    vector<int> executionOrder;
    int completed = 0;

    auto isReady = [&](int time, int pid) {
        return processes[pid].arrival <= time && remainingBurst[pid] > 0;
    };

    q.push(0);
    vector<bool> visited(n, false);
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (isReady(time, current)) {
            executionOrder.push_back(current);
            int burst = min(quantum, remainingBurst[current]);
            time += burst;
            remainingBurst[current] -= burst;

            if (remainingBurst[current] == 0) {
                processes[current].turnaround = time - processes[current].arrival;
                processes[current].waiting = processes[current].turnaround - processes[current].burst;
                completed++;
            }

            // Push new ready processes to queue
            for (int i = 0; i < n; i++) {
                if (!visited[i] && isReady(time, i)) {
                    q.push(i);
                    visited[i] = true;
                }
            }

            if (remainingBurst[current] > 0) q.push(current);
        }
    }

    // Print Results
    cout << "Execution Order: ";
    for (int pid : executionOrder) cout << "P" << pid + 1 << " ";
    cout << "\n";
    calculateAverageTime(processes);
}

void priorityScheduling(vector<Process> &processes, bool preemptive) {
    int time = 0, n = processes.size(), completed = 0;
    vector<int> remainingBurst(n);
    for (int i = 0; i < n; i++) remainingBurst[i] = processes[i].burst;

    vector<int> executionOrder;

    while (completed < n) {
        int idx = -1;
        int highestPriority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival <= time && remainingBurst[i] > 0 && processes[i].priority < highestPriority) {
                highestPriority = processes[i].priority;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        executionOrder.push_back(idx);

        if (preemptive) {
            time++;
            remainingBurst[idx]--;
        } else {
            time += remainingBurst[idx];
            remainingBurst[idx] = 0;
        }

        if (remainingBurst[idx] == 0) {
            processes[idx].turnaround = time - processes[idx].arrival;
            processes[idx].waiting = processes[idx].turnaround - processes[idx].burst;
            completed++;
        }
    }

    // Print Results
    cout << "Execution Order: ";
    for (int pid : executionOrder) cout << "P" << pid + 1 << " ";
    cout << "\n";
    calculateAverageTime(processes);
}

int main() {
    int n, choice, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    cout << "Enter Arrival Time, Burst Time, and Priority for each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i].arrival >> processes[i].burst >> processes[i].priority;
    }

    cout << "Select Scheduling Algorithm:\n";
    cout << "1. Priority Scheduling (Non-Preemptive)\n";
    cout << "2. Priority Scheduling (Preemptive)\n";
    cout << "3. Round Robin\n";
    cin >> choice;

    switch (choice) {
    case 1:
        priorityScheduling(processes, false);
        break;
    case 2:
        priorityScheduling(processes, true);
        break;
    case 3:
        cout << "Enter Time Quantum: ";
        cin >> quantum;
        roundRobin(processes, quantum);
        break;
    default:
        cout << "Invalid Choice!";
    }

    return 0;
}
