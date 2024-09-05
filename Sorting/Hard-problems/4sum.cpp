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
   //better
   /*int sum2;
   int f;
   set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        set<int>st1;
            for(int k=j+1;k<n;k++){
                    sum2=nums[i]+nums[j]+nums[k];
                    f=target-sum2;
                    if(st1.find(f)!=st1.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],f};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    st1.insert(nums[k]);
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
    //optimal
       vector<vector<int>>ans;
       sort(nums,nums+n);
       for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
             if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(l>k){
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum>target) l--;
                    else if(sum<target) k++;
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        l--;
                        k++;
                        while(l>k && nums[l]==nums[l+1]) l--;
                        while(l>k && nums[k]==nums[k-1]) k++;
                    }
                }
               
            }
    }
    for(int i=0;i<ans.size();i++){
            for(int p=0;p<4;p++){
                cout<<ans[i][p]<<",";
            }
            cout<<endl;
        }
    }
