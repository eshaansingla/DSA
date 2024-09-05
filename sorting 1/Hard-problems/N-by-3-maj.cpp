#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    cout<<"Enter a number:";
    cin>>arr[i];
    }
    //brute
    /*
        int max=INT_MIN;
        sort(arr.begin(),arr.end());
        int cnt1=0;
        int cnt2=0;
        int s;
        int m1,m2;
        for(int i=0;i<n;i++){
                s=arr[i];
            for(int j=0;j<n;j++){
                if(arr[j]==arr[i]) cnt1++;
            }
            if(cnt1>n/3){ 
                m1=arr[i];
                break;
            }
            cnt1=0;
        }
        for(int i=0;i<n;i++){
                s=arr[i];
            for(int j=0;j<n;j++){
                if(arr[j]==arr[i]) cnt2++;
            }
            if(cnt2>n/3 && s!=m1){ 
                m2=arr[i];
                break;
            }
            cnt2=0;
        }
        vector<int>res;
        if(cnt1>n/3) res.push_back(m1);
        if(cnt2>n/3 && s!=m1) res.push_back(m2);
        for(auto it:res) cout<<it<<" ";
        */
    //better
     /*   int n=arr.size();
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>max) max=arr[i];
        }

    set<int>at;
    map<int,int>hash;
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
        if(hash[arr[i]]>n/3){
             at.insert(arr[i]);
             }
    }
    vector<int>maj(at.begin(),at.end());
    for(auto it:maj) cout<<it<<" ";
    }
    */

   // optimal
   int cnt1=0,cnt2=0;
        int el1,el2;
        for(int i=0;i<n;i++){
            if(cnt1==0 && arr[i]!=el2){
                cnt1=1;
                el1=arr[i];
            }
            else if(cnt2==0 && arr[i]!=el1){
                cnt2=1;
                el2=arr[i];
            }
            else if(arr[i]==el1) cnt1++;
            else if(arr[i]==el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(el1==arr[i]) cnt1++;
            if(el2==arr[i]) cnt2++;
        }
        if(cnt1>n/3 && cnt2>n/3) cout<<el1<<" "<<el2<<endl;
        if(cnt1>n/3)cout<<el1<<endl;
        if(cnt2>n/3)cout<<el2<<endl;
        else cout<<"No element"<<endl;
    }