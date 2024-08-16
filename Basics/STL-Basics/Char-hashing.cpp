#include<bits/stdc++.h>
using namespace std;
int main(){
    string in;
    cout<<"Enter string:";
    getline(cin,in); 
    transform(in.begin(), in.end(), in.begin(), ::tolower); 
    int hash[256]={0};
    for(int i=0;i<256;i++){
        hash[in[i]]+=1;
    }
    char find;
    while(true){
        cout<<endl<<"Enter character to find:";
        cin>>find;
        find=(char)tolower(find);
        cout<<hash[find];
    }
    
}