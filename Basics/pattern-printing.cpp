#include<bits/stdc++.h>
using namespace std;
 void Sqaure(int n) {
     int spaces=0;
    for(int i=0;i<n;i++){
        if(i==0 || i==(n-1)){
           for(int j=0;j<n;j++){
               cout<<"*";
           }
    }
    else{
        for(int j=0;j<1;j++){
               cout<<"*";
           }
           for(int j=1;j<n-1;j++){
               cout<<" ";
           }
           for (int j = n - 1; j > n - 2; j--) {
               cout << "*";
           }
    }
    cout<<endl;
    }
 }
 void coolestofemall(int n) {
     for(int i=0;i<2*n-1;i++){
         for(int j=0;j<2*n-1;j++){
             int top=i;
             int left=j;
             int right=2*n-2-j;
             int down=2*n-2-i;
             cout<<n-min(min(top,down),min(left,right));
         }
         cout<<endl;
     }
 }
 void pattern6(int n){
   for(int i=1;i<=n;i++){
         for(int j=1;j<=i;j++){
             cout<<j<<" ";
         }
         for(int k=1;k<=(2*n)-(2*i);k++){
             cout<<" ";
         }
         for(int j=i;j>=1;j--){
             cout<<j<<" ";
         }
         cout<<endl;
     }
 }
 void pattern5(int n){
   for(int i=0;i<n;i++){
        for(int l=0;l<(n-i-1);l++){
            cout<<" ";
        }
        for (int k=0;k<2*i+1;k++){
            cout<<"*";
        }
        for (int j = 0; j < (n - i - 1); j++) {
            cout << " ";
        }
        cout<<endl;
     }
     for(int i=0;i<n;i++){
        for(int l=0;l<i;l++){
            cout<<" ";
        }
        for (int k=0;k<2*n - (2*i+1);k++){
            cout<<"*";
        }
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << endl;
     }
 }
 void pattern4(int n){
    int s=1;
     for(int i=0;i<n;i++){
         if(i%2==0) s=1;
         else s=0;
     for(int j=0;j<=i;j++){
         cout<<s<<" ";
         s=1-s;
     }
     cout<<endl;
 }
 }
 void pattern3(int n){
    for(int i=0;i<n;i++){
        for (int l=1;l<=i;l++){
            cout<<"*";
        }
        cout<<endl;
     }
     for(int i=0;i<n;i++){
        for (int k=n;k>i;k--){
            cout<<"*";
        }
        cout<<endl;
     }
 }
 void pattern2(int n){
     for(int i=0;i<n;i++){
        for(int l=0;l<i;l++){
            cout<<" ";
        }
        for (int k=0;k<2*n - (2*i+1);k++){
            cout<<"*";
        }
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        cout << endl;
    }
 }
 void  pasctributchars(int n){
   for(int i=0;i<n;i++){
         for(int j=0;j<n-i-1;j++){
             cout<<" ";
         }
         char ch='A';
         for(int j=0;j<(2*i+1);j++){
             if(j<(2*i+1)/2){
             cout<<ch<<" ";
             ch++;
             }
             else{
                cout<<ch<<" ";
             ch--; 
             }
         }
         for (int j = 0; j < n - i - 1; j++) {
             cout << " ";
         }
         cout << endl;
     }
 }
 void ccbcba(int n){
   char ch='A';
     ch+=n-1;
     for(int i=0;i<n;i++){
         for(int j=0;j<=i;j++){
             cout<<ch<<" ";
             ch--;
         }
         ch='A';
         ch+=n-1;
         cout<<endl;
     }
 }
 void continuousletters(int n){
    int a=n;
     for(int i=0;i<=n;i++){
         for(char j='A';j<'A'+a;j++){
             cout<<j<<" ";
         }
         a--;
         cout<<endl;
     }
 }
 void letteredtriangles(int n) {
    char ch='A';
     for(int i=1;i<=n;i++){
         for(int j=1;j<=i;j++){
             cout<<ch<<" ";
             ch++;
         }
         cout<<endl;
     }
 }
 void patternnum(int n){
    for(int i=n;i>=1;i--){
 			for(int j=1;j<=i;j++){
 				cout<<j<<" ";
 			}
 			cout<<endl;
 		}
 }
 void patternnums(int n){
 	for(int i=1;i<=n;i++){
 			for(int j=1;j<=i;j++){
 				cout<<i<<" ";
 			}
 			cout<<endl;
 		}
 }
 void starrev(int n){
   	for(int i=0;i<n;i++){
 			for(int j=n;j>i;j--){
 				cout<<"* ";
 			}
 			cout<<endl;
 		}
 }
 void first(int n){
 	for(int i=0;i<n;i++){
 			for(int j=0;j<n;j++){
 				cout<<"* ";
 			}
 			cout<<endl;
 		}
 }
 void cont(int n){
 int sum=1;
     for(int i=1;i<=n;i++){
         for(int j=1;j<=i;j++){
             cout<<sum<<" ";
             sum++;
         }
         cout<<endl;
     }
 }
int main(){
  int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int n;
    cin>>n;
    //enterDifferentFunctions(n);
  }
}
