#include<bits/stdc++.h>
using namespace std;
// the element = rows-1 C columns-1

int facto(int n){
    if(n==1||n==0) return 1;
    else return n*facto(n-1);
}

int myf(int r,int c){
return facto(r-1)/(facto(c-1)*facto(r-c));
}
//brute
/*
void rowprinter(){
    int row,column;
    cout<<"Enter row:";
    cin>>row;
    column=row;
    for(int i=1;i<=column;i++) cout<<myf(row,i)<<" ";
}
*/
int main(){
    int row,column;
    cout<<"Enter number of rows:";
    cin>>row;
    cout<<"Enter number of columns:";
    cin>>column;
    cout<<"THE ELEMENT IS: "<<myf(row,column)<<endl;
    rowprinter();
}
