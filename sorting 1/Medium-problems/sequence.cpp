#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    vector<int>arr(n);
    int sum;
    for(int i=0;i<n;i++){
        cout<<"Enter a number:";
        cin>>arr[i];
    }
    //brute
    /*sort(arr.begin(),arr.end());
    int no=1;
    int cnt=1;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]==arr[i]) continue;
        if(arr[i+1]-arr[i]==1){
            no++;
            cnt=max(cnt,no);
        }
        else{
            no=1;
        }
    }
    cout<<cnt<<endl;
    */
    //optimal
    if (arr.empty()) cout<< 0;
        set<int> st(arr.begin(), arr.end());
        int longestStreak = 0;
        for (auto num : st) {
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int currentStreak = 1;
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentStreak++;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        cout<<longestStreak<<endl;
    }