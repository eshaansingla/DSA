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
class stack{
    public:
    Node*top;
    int size;
     stack() {
        top = nullptr;
        size = 0;     
    }
    void push(int x){
        Node*temp=new Node(x,top);
        top=temp;
        size++;
    }
    void Top(){
        cout<<top->data<<endl;
    }
    void pop(){
        if(size<=0){
            cout<<"Underflow"<<endl;
        }
        else{
        Node*temp=top;
        top=top->next;
        delete temp;
        size--;
    }
    }
    void Size(){
        cout<<this->size<<endl;
    }
};
class queue{
    public:
    Node*start;
    Node*end;
    int size;
    queue(){
        start=nullptr;
        end=nullptr;
        size=0;
    }
    void push(int x){
        Node*temp=new Node(x);
        if(size==0){
            start=temp;
            end=temp;
        }
        else{ 
            end->next=temp;
            end=end->next;
        }
        size++;
    }
    void Size(){
        cout<<this->size<<endl;
    }
    void Top(){
        cout<<start->data<<endl;
    }
    void pop(){
        if(size<=0){
            cout<<"Underflow"<<endl;
        }
        else{
            size--;
            Node*temp=start;
            start=start->next;
            delete temp;
        }
    }
};
int main(){
    //stack s;
    queue s;
    s.push(69);
    //s.Size();
    //s.Top();
    s.push(6);
    //s.Top();
    //s.Size();
    s.push(9);
    s.Top();
    //s.Size();
    s.push(5);
    s.pop();
    s.Top();
    s.pop();
    s.Top();
}