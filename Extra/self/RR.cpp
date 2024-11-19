#include<bits/stdc++.h>
using namespace std;
class Process{
public:
int arrival;
string pid;
int burst;
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
    for (int i = 0; i < n; i++) {
    cout << "Enter Process ID, Arrival Time, and Burst Time for process " << i + 1 << ": ";
    cin >> processes[i].pid >> processes[i].arrival >> processes[i].burst;
    processes[i].rem=processes[i].burst;
}
int tq;
cout<<"Enter time quantum: ";
cin>>tq;
sort(processes.begin(),processes.end(),[](Process &a,Process &b){
    return a.arrival<b.arrival;
});
queue<int>ready;
vector<bool>inqueue(n,false);
int completed=0;
int curtime=0;
while(completed!=n){
for(int i=0;i<n;i++){
    if(processes[i].rem>0 && !inqueue[i] && processes[i].arrival<=curtime){
        ready.push(i);
        inqueue[i]=true;
    }
}
    if(!ready.empty()){
        int idx=ready.front();
        ready.pop();
        inqueue[idx]=false;
        int exec=min(tq,processes[idx].rem);
        processes[idx].rem-=exec;
        curtime+=exec;
        if(processes[idx].rem==0){
            processes[idx].comp=curtime;
            processes[idx].tat=processes[idx].comp-processes[idx].arrival;
            processes[idx].wt=processes[idx].tat-processes[idx].burst;
            completed++;
        }
        else{
            ready.push(idx);
            inqueue[idx]=true;
        }

    }
    else{
            curtime++;
        }
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