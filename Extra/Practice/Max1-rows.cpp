#include <iostream>
using namespace std;
int main() {
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
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int cnt=0;
    int maxi=0;
    int ans=0;
    int i;
    for(i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]==1) cnt++;
        }
        if(cnt>maxi){ 
            maxi=cnt;
            ans=i;
        }
        cnt=0;
    }
    cout<<ans+1<<endl;
}