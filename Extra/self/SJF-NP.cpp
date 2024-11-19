#include<bits/stdc++.h>
using namespace std;
class Process{
public:
string pid;
int arrival;
int burst;
int completion;
int waiting;
int tat;
Process(){
    arrival=0;
    burst=0;
    completion=0;
    waiting=0;
    tat=0;
}
};
int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<Process>processes(n);
    for (int i = 0; i < n; i++) {
    cout << "Enter Process ID, Arrival Time, and Burst Time for process " << i + 1 << ": ";
    cin >> processes[i].pid >> processes[i].arrival >> processes[i].burst;
}
    sort(processes.begin(),processes.end(),[](Process&a,Process&b){
        if(a.arrival!=b.arrival) return a.arrival<b.arrival;
        return a.burst<b.burst;
    });
    int curtime=0;
    for(int i=0;i<n;i++){
        if(processes[i].arrival>curtime) curtime=processes[i].arrival;
        curtime+=processes[i].burst;
        processes[i].completion=curtime;
        processes[i].tat=processes[i].completion-processes[i].arrival;
        processes[i].waiting=processes[i].tat-processes[i].burst;
        }
    cout << "\nPid\tArrival\tBurst\tCompletion\tTAT\tWaiting\n";
    float avgtat=0,avgwt=0;
    for (const auto &process : processes) {
        avgtat+=process.tat;
        avgwt+=process.waiting;
        cout << process.pid << "\t"
             << process.arrival << "\t"
             << process.burst << "\t"
             << process.completion << "\t\t"
             << process.tat << "\t"
             << process.waiting << "\n";
    }
    cout<<"Average Waiting Time: "<<avgwt/n<<endl;
    cout<<"Average Turn Around Time: "<<avgtat/n<<endl;
}