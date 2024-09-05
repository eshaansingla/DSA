#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    int arr[n];
    int sum;
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    //brute
    /* int target;
    bool flag=true;
    vector<int>v;
    for(int i=0;i<n;i++){
        target=arr[i];
        flag=true;
        for(int j=i+1;j<n;j++){
            if(arr[j]>target){
                flag=false;
                break;
            }
        }
        if(flag==true) v.push_back(target);
    }
    for(auto it:v) cout<<it<<endl; */

    //optimal
    int maxi=INT_MIN;
    vector<int>sol;
    for(int i=n-1;i>=0;i--){
        if(maxi<arr[i]){ 
        maxi=arr[i];
        sol.push_back(maxi);
        }
    }
    for(auto it:sol) cout<<it<<endl;
    }