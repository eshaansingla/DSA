#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
    stack<int>s1,s2;
    void push(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop(){
        s1.pop();
}
void front(){
    cout<< s1.top()<<endl;
}
};
int main(){
Queue s;
s.push(9);
s.front();
s.pop();
s.push(6);
s.front();
s.push(10);
s.front();
s.push(2);
s.front();
s.pop();
s.front();
}