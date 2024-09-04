#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cout<<"Enter a number: ";
    cin>>x;
    long long product;
       if(x==1) return 1;
       for(long long j=0;j<=x/2;j++){
        if(j*j<=x){
            product=j;
        }
        else break;
       }
       cout<<product<<endl;
    }
