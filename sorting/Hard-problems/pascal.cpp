#include<bits/stdc++.h>
using namespace std;
// the element = rows-1 C columns-1
//brute
/*
int facto(int n){
    if(n==1||n==0) return 1;
    else return n*facto(n-1);
}

int myf(int r,int c){
return facto(r-1)/(facto(c-1)*facto(r-c));
}
void rowprinter(){
    int row,column;
    cout<<"Enter row:";
    cin>>row;
    column=row;
    for(int i=1;i<=column;i++) cout<<myf(row,i)<<" ";
}

vector<vector<int>> generate(int numRows) {
        int col=1;
        vector<int>v;
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            for(int j=1;j<=col;j++){
                v.push_back(myf(i,j));
            }
            col++;
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
    
int main(){
    int row,column;
    cout<<"Enter number of rows:";
    cin>>row;
    cout<<"Enter number of columns:";
    cin>>column;
    cout<<"THE ELEMENT IS: "<<myf(row,column)<<endl;
    rowprinter();
    vector<vector<int>>Arrayrows=generate(row);
}
    */
//optimal
int main(){
int ans=1;
int row,column;
cout<<"Enter the row number:";
cin>>row;
column=row;
cout<<1<<" ";
for(int i=1;i<column;i++){
    ans=(ans*(row-i))/i;
    cout<<ans<<" ";
}
}

