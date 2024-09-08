#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int data){
this->data=data;
this->next=nullptr;
}
Node(int data,Node*next){
this->data=data;
this->next=next;
}
};
class Stack{
public:
int size=0;
Node*top;
void push(int x){
Node*temp=new Node(x);
temp->next=top;
top=temp;
size++;
}
int Top(){
    return top->data;
}
void pop(){
    Node*temp=top;
    top=top->next;
    delete temp;
    size--;
}
int Size(){
    return size;
}
};
int main(){
Stack s;
for(int i=1;i<=100;i++) {
s.push(i);
cout<<s.Top()<<endl;
}
cout<<s.Top()<<endl;
cout<<s.Size()<<endl;
}