#include<bits/stdc++.h>
using namespace std;
class Process{
public:
int arrival;
string pid;
int burst;
int p;
int wt;
int tat;
int comp;
int rem;
Process(){
    wt = tat = comp = 0;
}
};
int main(){
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    vector<Process>processes(n);
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while(completed!=n){
        for(int i=0;i<n;i++){
            if(processes[i].rem>0 && processes[i].arrival<=curtime){
                pq.push({processes[i].p,i});
            }
        }
        if(!pq.empty()){
            int idx=pq.top().second;
            pq.pop();
            processes[idx].rem--;
            curtime++;
            if(processes[idx].rem==0){
                processes[idx].comp=curtime;
                processes[idx].tat=processes[idx].comp-processes[idx].arrival;
                processes[idx].wt=processes[idx].tat-processes[idx].burst;
                completed++;
            }
        }
        else curtime++;
    }
float avgtat=0,avgwt=0;
cout << "\nPid\tArrival\tBurst\tCompletion\tTAT\tWaiting\n";
 for (const auto &process : processes) {
        avgtat += process.tat;
        avgwt += process.wt;
        cout << process.pid << "\t"
             << process.arrival << "\t"
             << process.burst << "\t"
             << process.comp << "\t\t"
             << process.tat << "\t"
             << process.wt << "\n";
    }
    cout << "Average Waiting Time: " << avgwt / n << endl;
    cout << "Average Turn Around Time: " << avgtat / n << endl;
}
