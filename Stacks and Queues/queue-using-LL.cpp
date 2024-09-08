#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int data){
    this->data=data;
}
};
class Queue{
public:
int size=0;
Node*start=nullptr;
Node*end=nullptr;
void push(int x){
if(start==nullptr){
    Node*temp=new Node(x);
    start=temp;
    end=temp;
}
else{
     Node*temp=new Node(x);
     end->next=temp;
     end=temp;
}
size++;
}
int front(){
return start->data;
}
void pop(){
if(start==nullptr) cout<<"NAH"<<endl;
else{
    Node*temp=start;
    start=start->next;
    delete temp;
    size--;
}
}
int Size(){
    return size;
}
};
int main(){
Queue q;
q.push(69);
q.push(1);
q.push(29);
q.push(7);
q.push(69);
q.push(1);
q.push(29);
q.push(7);
cout<<q.front()<<endl;
q.pop();
cout<<q.front()<<endl;
cout<<q.Size();
}