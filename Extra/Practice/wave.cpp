#include<iostream>
using namespace std;
int main(){
    int r;
    int c;
    cout<<"Enter rows:";
    cin>>r;
    cout<<"Enter columns:";
    cin>>c;
    int a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<"Enter:";
            cin>>a[i][j];
        }
    }
    /*
    1 2 3
    4 5 6
    7 8 9

    1 2 3 6 5 4 7 8 9
    */
   for(int k=0;k<r;k++)
   if(k%2==0){
    for(int j=0;j<c;j++){
        cout<<a[k][j]<<" ";
   }
   }
   else{
        for(int j=c-1;j>=0;j--){
            cout<<a[k][j]<<" ";
        }
    }
    }