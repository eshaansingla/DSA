#include<iostream>
using namespace std;
int main(){
int r,c;
cout<<"Enter number of rows: ";
cin>>r;
cout<<"Enter number of columns: ";
cin>>c;
int arr[r][c];
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cout<<"Enter element: ";
        cin>>arr[i][j];
    }
}
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl<<"Wave-1: "<<endl;
for(int i=0;i<r;i++){
    if(i%2==0){
    for(int j=0;j<c;j++){
        cout<<arr[i][j]<<" ";
    }
    }
    else{
       for(int j=c-1;j>=0;j--){
        cout<<arr[i][j]<<" ";
    } 
    }
    cout<<endl;
}
cout<<endl;
cout<<endl<<"Wave-2: "<<endl;
for(int j=0;j<c;j++){
    if(j%2!=0){
    for(int i=0;i<r;i++){
        cout<<arr[i][j]<<" ";
    }
    }
    else{
       for(int i=r-1;i>=0;i--){
        cout<<arr[i][j]<<" ";
    } 
    }
    cout<<endl;
}
cout<<endl;
cout<<"TRANSPOSE MATRIX: "<<endl;
for(int i=0;i<r;i++){
    for(int j=i;j<c;j++){
        int temp=arr[i][j];
        arr[i][j]=arr[j][i];
        arr[j][i]=temp;
    }
}
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl;
cout<<"ROTATED MATRIX: "<<endl;
for(int i=0;i<r;i++){
    for(int j=0;j<c/2;j++){
        int temp=arr[i][j];
        arr[i][j]=arr[i][c-j-1];
        arr[i][c-j-1]=temp;
    }
    }
for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
}