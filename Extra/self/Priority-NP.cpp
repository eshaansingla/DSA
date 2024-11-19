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
Process(){
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
    }
    sort(processes.begin(),processes.end(),[](Process &a,Process&b){
        if(a.arrival!=b.arrival) return a.arrival<b.arrival;
        return b.p>a.p;
    });
    int curtime=0;
    for(int i=0;i<n;i++){
        if(curtime<processes[i].arrival) curtime=processes[i].arrival;
        curtime+=processes[i].burst;
        processes[i].comp=curtime;
        processes[i].tat=processes[i].comp-processes[i].arrival;
        processes[i].wt=processes[i].tat-processes[i].burst;
        }
    cout << "\nPid\tArrival\tBurst\tCompletion\tTAT\tWaiting\n";
    float avgtat=0,avgwt=0;
    for (const auto &process : processes) {
        avgtat+=process.tat;
        avgwt+=process.wt;
        cout << process.pid << "\t"
             << process.arrival << "\t"
             << process.burst << "\t"
             << process.comp << "\t\t"
             << process.tat << "\t"
             << process.wt << "\n";
    }
    cout<<"Average Waiting Time: "<<avgwt/n<<endl;
    cout<<"Average Turn Around Time: "<<avgtat/n<<endl;
}
