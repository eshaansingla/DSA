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
    for(int i=0;i<r;i++){
    for(int j=i;j<c;j++){
        if(i==j) continue;
        else{
            int temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }
    }
    for(int i=0;i<r;i++){
            int j=0;
            int k=c-1;
            while(j<k){
                int temp=a[i][j];
                a[i][j]=a[i][k];
                a[i][k]=temp;
                j++;
                k--;
            }
        }
        for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }
    
}