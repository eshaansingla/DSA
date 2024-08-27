#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
    cout<<"Enter a number:";
    cin>>nums[i];
    }
    int target;
    cout<<"Enter sum:";
    cin>>target;
    //brute
    /*
    int sum2;
        set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    sum2=nums[i]+nums[j]+nums[k]+nums[l];
                    if(target==sum2){
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
    }
    }
    }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    for(int i=0;i<ans.size();i++){
            for(int p=0;p<4;p++){
                cout<<ans[i][p]<<",";
            }
            cout<<endl;
        }
    */
}