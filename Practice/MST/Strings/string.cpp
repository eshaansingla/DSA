#include<iostream>
using namespace std;
#include<string>
int main(){
char ch;
cout<<"Enter capital: ";
cin>>ch;
cout<<"Lowercase: "<<char(ch+32)<<endl;
cout<<"Uppercase: "<<char(ch-32)<<endl;
string s1="Eshaan";
string s2="Singla";
string s3;
s1=s1+s2;
cout<<s1;
}