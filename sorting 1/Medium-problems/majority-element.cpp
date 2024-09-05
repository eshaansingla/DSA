#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    int sum;
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    //brute hash and display if index>n/2
    //better
        /* sort(arr,arr+n);
        int no=1;
        int cnt=0;
        int maxi=-1;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]) no++;
            else{
                if(cnt<no){
                    cnt=no;
                    maxi=arr[i-1];
                }
                no=1;
            }
        }
        if (no > cnt) {
            cnt = no;
            maxi = arr[n-1];
        }
        
        if (cnt > n / 2) cout<<maxi<<endl;
        else cout<<"No element."<<endl; */
    //optimal
        int maj=arr[0];
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0) maj=arr[i];
            if(maj==arr[i]) cnt++;
            else{
                cnt--;
            }
        }
        cout<<maj<<endl;
}