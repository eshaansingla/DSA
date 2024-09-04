#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    //brute
    /*
    long long product;
       if(x==1) return 1;
       for(long long j=0;j<=x/2;j++){
        if(j*j<=x){
            product=j;
        }
        else break;
       }
       cout<<product<<endl;
    */
   //optimal

       int low=1;
       int high=x;
       long long mid;
       int ans;
       if(x==0) return 0;
       while(low<=high){
        mid= low + (high-low)/2;
        if(mid*mid>x) high=mid-1;
        else{
            ans=mid;
            low=mid+1;
        }
       }
       return ans;
   }
