#include<bits/stdc++.h>
using namespace std;
class Stack{
public:
queue<int>q;
void push(int x){
int s=q.size();
q.push(x);
for(int i=0;i<s;i++){
    q.push(q.front());
    q.pop();
}
}
void pop(){
    q.pop();
}
void top(){
    cout<< q.front()<<endl;
}
};
int main(){
Stack s;
s.push(9);
s.top();
s.pop();
s.push(6);
s.top();
s.push(10);
s.top();
s.push(2);
s.top();
s.pop();
s.top();
}