#include<bits/stdc++.h>
using namespace std;
int main(){
    /* int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter value:";
        cin>>arr[i];
    }
    int cnt=0;
    int j=-1;
    for (int i=0;i<n;i++) {
        if (arr[i] == 0) {
            j=i;
            break;
        }
    }
    for(int i=j+1;j<n;j++){
        if(arr[i]!=0) swap(arr[i],arr[j]);
    }
    for(auto it:arr) cout<<it<<endl;
*/
    int n;
    cout<<"Enter n:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter value:";
        cin>>arr[i];
    }
    int j=-1;
    for (int i=0;i<n;i++) {
        if (arr[i] == 0) {
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
        swap(arr[i],arr[j]);
        j++;
        }
    }
    for(auto it:arr) cout<<it<<endl;
}