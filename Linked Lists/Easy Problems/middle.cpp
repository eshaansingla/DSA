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
/*
int count(Node*head){
    int cnt=0;
    while(head){
        cnt++;
        head=head->next;
    }
    return cnt;
}
void display(Node*head,int cnt){
Node*temp=head;
while(cnt>0){
    temp=temp->next;
    cnt--;
}
while(temp){
    cout<<temp->data<<endl;
    temp=temp->next;
}
}
*/
void display(Node*head){
    Node*temp=head;
    while(temp){
    cout<<temp->data<<endl;
    temp=temp->next;
}
}
Node*calc(Node*head){
Node*slow=head;
Node*fast=head;
while(fast&& fast->next){
    slow=slow->next;
    fast=fast->next->next;
}
display(slow);
}
};
int main(){
Node*p=new Node(1);
p->next=new Node(2);
p->next->next=new Node(3);
p->next->next->next=new Node(4);
p->next->next->next->next=new Node(5);
p->next->next->next->next->next=new Node(6);
p->calc(p);
}