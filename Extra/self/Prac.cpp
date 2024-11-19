/*#include<bits/stdc++.h>
using namespace std;
class Process{
    public:
    int comp;
    int burst;
    int arrival;
    string pid;
    int tat;
    int wt;
    int p;
    Process(){
        wt=0;
        tat=0;
        comp=0;
    }
};
// <-----------------------FCFS----------------------->
/*
int main(){
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    vector<Process>processes(n);
    for(int i=0;i<n;i++){
        cout<<"Enter process id, arrival time, burst time: ";
        cin>>processes[i].pid>>processes[i].arrival>>processes[i].burst;
    }
    sort(processes.begin(),processes.end(),[](Process &a,Process &b){
        return a.arrival<b.arrival;
    });
    int curtime=0;
    for(int i=0;i<n;i++){
        if(curtime<processes[i].arrival) curtime=processes[i].arrival;
        curtime+=processes[i].burst;
        processes[i].comp=curtime;
        processes[i].tat=processes[i].comp-processes[i].arrival;
        processes[i].wt=processes[i].tat-processes[i].burst;
    }
    cout<<"PId\tArrival Time\tBurst Time\tTurn Around Time\tWaiting Time"<<endl;
    float avgtat=0;
    float avgwt=0;
    for(const auto &process:processes){
        avgtat+=process.tat;
        avgwt+=process.wt;
        cout<<process.pid<<"\t\t"<<process.arrival<<"\t\t"<<process.burst<<"\t\t"<<process.tat<<"\t\t"<<process.wt<<endl;
    }
    cout<<"Average Turn Around Time: "<<avgtat/n<<endl;
    cout<<"Average Waiting Time: "<<avgwt/n<<endl;
    }
*/
// <-----------------------SJF NP----------------------->
/*
int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID, Arrival Time, and Burst Time for process " << i + 1 << ": ";
        cin >> processes[i].pid >> processes[i].arrival >> processes[i].burst;
    }

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), [](Process &a, Process &b) {
        return a.arrival < b.arrival;
    });

    int curtime = 0;          // Current time
    int completed = 0;        // Number of completed processes
    vector<bool> isCompleted(n, false); // To track completed processes
        for(int i=0;i<n;i++){
            if(!check[i] && processes[i].arrival<shortest && processes[i].arrival<=curtime){
                shortest=processes[i].burst;
                idx=i;
            }
        }
        if(idx==-1) curtime++;
        else{
            completed++;
            curtime+=processes[idx].burst;
            processes[idx].completion=curtime;
            processes[idx].tat=processes[idx].completion-processes[idx].arrival;
            processes[idx].waiting=processes[idx].tat-processes[idx].burst;
            check[idx]=true;
        }
    }
    while (completed < n) {
        int idx = -1;
        int shortest = INT_MAX;

        // Find the shortest burst time among arrived processes that are not completed
        for (int i = 0; i < n; i++) {
            if (!isCompleted[i] && processes[i].arrival <= curtime && processes[i].burst < shortest) {
                shortest = processes[i].burst;
                idx = i;
            }
        }

        if (idx == -1) {
            // If no process is available to execute, increment the current time
            curtime++;
        } else {
            // Execute the selected process
            curtime += processes[idx].burst;
            processes[idx].completion = curtime;
            processes[idx].tat = processes[idx].completion - processes[idx].arrival;
            processes[idx].waiting = processes[idx].tat - processes[idx].burst;
            isCompleted[idx] = true;
            completed++;
        }
    }

    // Print results
    cout << "\nPid\tArrival\tBurst\tCompletion\tTAT\tWaiting\n";
    float totalTAT = 0, totalWT = 0;

    for (const auto &process : processes) {
        totalTAT += process.tat;
        totalWT += process.waiting;
        cout << process.pid << "\t"
             << process.arrival << "\t"
             << process.burst << "\t"
             << process.completion << "\t\t"
             << process.tat << "\t"
             << process.waiting << "\n";
    }

    cout << "Average Waiting Time: " << totalWT / n << endl;
    cout << "Average Turn Around Time: " << totalTAT / n << endl;

    return 0;
}
*/
/*
int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<bool>check(n,0);
    vector<Process>processes(n);
    for(int i=0;i<n;i++){
        cout << "Enter Process ID, Arrival Time, and Burst Time for process " << i + 1 << ": ";
        cin >> processes[i].pid >> processes[i].arrival >> processes[i].burst;
    }
    sort(processes.begin(),processes.end(),[](Process &a, Process &b){
        return a.arrival<b.arrival;
    });
    int curtime=0;
    int completed=0;
    while(completed!=n){
        int idx=-1;
        int shortest=INT_MAX;
        for(int i=0;i<n;i++){
            if(!check[i] && processes[i].burst<shortest && processes[i].arrival<=curtime){
                shortest=processes[i].burst;
                idx=i;
            }
        }
        if(idx==-1) curtime++;
        else{
            completed++;
            curtime+=processes[idx].burst;
            processes[idx].completion=curtime;
            processes[idx].tat=processes[idx].completion-processes[idx].arrival;
            processes[idx].waiting=processes[idx].tat-processes[idx].burst;
            check[idx]=true;
        }
    }
    cout << "\nPid\tArrival\tBurst\tCompletion\tTAT\tWaiting\n";
    float totalTAT = 0, totalWT = 0;

    for (const auto &process : processes) {
        totalTAT += process.tat;
        totalWT += process.waiting;
        cout << process.pid << "\t"
             << process.arrival << "\t"
             << process.burst << "\t"
             << process.completion << "\t\t"
             << process.tat << "\t"
             << process.waiting << "\n";
    }

    cout << "Average Waiting Time: " << totalWT / n << endl;
    cout << "Average Turn Around Time: " << totalTAT / n << endl;

}
*/
/*
int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<Process>processes(n);
    vector<bool>check(n,0);
    for(int i=0;i<n;i++){
        cout << "Enter Process ID, Arrival Time, and Burst Time for process " << i + 1 << ": ";
        cin >> processes[i].pid >> processes[i].arrival >> processes[i].burst;
        processes[i].rem=processes[i].burst;
    }
    sort(processes.begin(),processes.end(),[](Process &a, Process &b){
        return a.arrival<b.arrival;
    });
    int curtime=0;
    int completed=0;
    while(completed!=n){
        int idx=-1;
        int shortest=INT_MAX;
        for(int i=0;i<n;i++){
            if(processes[i].rem>0 && processes[i].rem<shortest && processes[i].arrival<=curtime){
                idx=i;
                shortest=processes[i].rem;
            }
        }
        curtime++;
        processes[idx].rem--;
        if(idx==-1){
            curtime++;
            continue;
        }
        if(processes[idx].rem==0){
            completed++;
            processes[idx].completion=curtime;
            processes[idx].tat=processes[idx].completion-processes[idx].arrival;
            processes[idx].waiting=processes[idx].tat-processes[idx].burst;
        }
    }
cout << "\nPid\tArrival\tBurst\tCompletion\tTAT\tWaiting\n";
    float totalTAT = 0, totalWT = 0;

for (const auto &process : processes) {
        totalTAT += process.tat;
        totalWT += process.waiting;
        cout << process.pid << "\t"
             << process.arrival << "\t"
             << process.burst << "\t"
             << process.completion << "\t\t"
             << process.tat << "\t"
             << process.waiting << "\n";
    }

    cout << "Average Waiting Time: " << totalWT / n << endl;
    cout << "Average Turn Around Time: " << totalTAT / n << endl;

}
*/
#include <bits/stdc++.h>
using namespace std;

class Process {
public:
    string pid;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int tat;
    int p;
    int rem;
    Process() {
        arrival = 0;
        burst = 0;
        completion = 0;
        waiting = 0;
        tat = 0;
        rem=0;
    }
};
int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<Process>processes(n);
    vector<bool>check(n,0);
    for(int i=0;i<n;i++){
    cout << "Enter Process ID, Arrival Time, Burst Time amd Priority for process " << i + 1 << ": ";
    cin >> processes[i].pid >> processes[i].arrival >> processes[i].burst >> processes[i].p ;
    processes[i].rem=processes[i].burst;
    }
    sort(processes.begin(),processes.end(),[](Process &a,Process &b){
        if(a.arrival!=b.arrival) return a.arrival<b.arrival;
        return a.p<b.p;
    });
    int completed=0;
    int curtime=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    while(completed!=n){
        for(int i=0;i<n;i++){
            if(!check[i] && processes[i].arrival<=curtime){
            pq.push({processes[i].p,i});
            check[i]=true;
            }
        }
        if(!pq.empty()){
            int idx=pq.top().second;
            pq.pop();
            curtime+=processes[idx].burst;
            processes[idx].completion=curtime;
            processes[idx].tat=processes[idx].completion-processes[idx].arrival;
            processes[idx].waiting=processes[idx].tat-processes[idx].burst;
            completed++;
        }
        else curtime++;
    }
float avgtat=0,avgwaiting=0;
cout << "\nPid\tArrival\tBurst\tCompletion\tTAT\tWaiting\n";
 for (const auto &process : processes) {
        avgtat += process.tat;
        avgwaiting += process.waiting;
        cout << process.pid << "\t"
             << process.arrival << "\t"
             << process.burst << "\t"
             << process.completion << "\t\t"
             << process.tat << "\t"
             << process.waiting << "\n";
    }
    cout << "Average Waiting Time: " << avgwaiting / n << endl;
    cout << "Average Turn Around Time: " << avgtat / n << endl;
}
