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
int rem;
Process(){
    arrival=0;
    burst=0;
    completion=0;
    waiting=0;
    tat=0;
    rem=0;
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
    processes[i].rem=processes[i].burst;
}
sort(processes.begin(),processes.end(),[](Process &a,Process &b){
    return a.arrival<b.arrival;
});
int curtime=0;
int comp=0;
while(comp!=n){
int idx=-1;
int shortest=INT_MAX;
for(int i=0;i<n;i++){
if(processes[i].arrival<=curtime && processes[i].rem<shortest && processes[i].rem>0){
    shortest=processes[i].rem;
    idx=i;
}
}
if(idx==-1){
    curtime++;
    continue;
}
processes[idx].rem--;
curtime++;
if(processes[idx].rem==0){
comp++;
processes[idx].completion=curtime;
processes[idx].tat=processes[idx].completion-processes[idx].arrival;
processes[idx].waiting=processes[idx].tat-processes[idx].burst;
}
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