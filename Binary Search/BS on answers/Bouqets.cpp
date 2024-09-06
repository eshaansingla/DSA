#include<bits/stdc++.h>
using namespace std;
int bouqets(vector<int>& day, int k,int mid){
int flower=0;
int bouqet=0;
for(int i=0;i<day.size();i++){
if(day[i]<=mid){
    flower++;
    if(flower==k){
        bouqet++;
        flower=0;
    }
    }
else flower=0;
}
return bouqet;
}
int minDays(vector<int>& day, int m, int k) {
int n=day.size();
int low=*min_element(day.begin(),day.end());
int high=*max_element(day.begin(),day.end());
int mid;
int bouq;
if(n<(long long)m*k) return -1;
while(low<=high){
    mid= low + (high-low)/2;
    bouq=bouqets(day,k,mid);
    if(bouq>=m) high=mid-1;
    else low=mid+1;
}
return low;
}
int main(){
int n;
cout<<"Enter n:";
cin>>n;
vector<int>bloomday(n);
int k;
cout<<"Enter the number of adjacent flowers required:";
cin>>k;
int m;
cout<<"Enter the number of bouqets required:";
cin>>m;
for(int i=0;i<bloomday.size();i++){
    cout<<"Enter the days required for the flower to bloom: ";
    cin>>bloomday[i];
}
cout<<minDays(bloomday,m,k)<<endl;
}