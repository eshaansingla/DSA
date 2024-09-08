#include<iostream>
using namespace std;
int arr[100];
int n=100;
int start=-1;
int End=-1;
int cursize=0;
class Queue{
public:
void push(int x){
if(cursize==0) start=0,End=0,arr[End]=x;
else{ 
    End=(End+1)%n;
    arr[End]=x;
}
cursize++;
}
int top(){
return arr[start];
}
void pop(){
    start=(start+1)%n;
    cursize--;
}
int size(){
        return cursize;
    }
};
int main(){
Queue q;
q.push(69);
q.push(1);
q.push(29);
q.push(7);
cout<<q.top()<<endl;
q.pop();
cout<<q.top()<<endl;
cout<<q.size();
}