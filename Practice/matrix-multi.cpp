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
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;
    }
    int r1;
    int c1;
    cout<<"Enter rows:";
    cin>>r1;
    cout<<"Enter columns:";
    cin>>c1;
    int b[r1][c1];
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cout<<"Enter:";
            cin>>b[i][j];
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cout<<b[i][j]<<"  ";
        }
        cout<<endl;
    }
    int d[r][c1];
    if(c==r1){
        for(int i=0;i<r;i++){
        for(int j=0;j<c1;j++){
            d[i][j]=0;
            for(int k=0;k<c;k++){
            d[i][j]+=a[i][k]*b[k][j];
            
        }
        }
    }
    }
    else cout<<"Not possible."<<endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c1; j++) {
            cout << d[i][j] << "  ";
        }
        cout << endl;
    }
}