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
void print(Node*head){
Node*temp=head;
while(temp){
    cout<<temp->data<<endl;
    temp=temp->next;
}
}
void search(Node*head,int val){
Node*temp=head;
while(temp){
    if(temp->data==val){
        cout<<"found"<<endl;
    }
    temp=temp->next;
}
}
Node*del(Node*head,int val){
if(head->data==val){
    Node*delnode=head;
    head=head->next;
    delete delnode;
    return head;
}
Node*temp=head;
while(temp){
    if(temp->next->data==val){
        Node*delnode=temp->next;
        temp->next=temp->next->next;
        delete delnode;
        return head;
    }
    temp=temp->next;
}
}
Node*insert(Node*head,int val,int bef){
if(head->data==bef){
    return new Node(val,head);
}
Node*temp=head;
while(temp){
    if(temp->next->data==bef){
        temp->next=new Node(val,temp->next);
        return head;
    }
    temp=temp->next;
}
}
void middle(Node*head){
    Node*slow=head;
    Node*fast=head;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"Middle is: "<<slow->data<<endl;
}
Node*reverse(Node*head){
Node*temp=head;
Node*prev=nullptr;
Node*front=nullptr;
while(temp){
    front=temp->next;
    temp->next=prev;
    prev=temp;
    temp=front;
}
return prev;
}
void detectloop(Node*head){
Node*slow=head;
Node*fast=head;
while(fast->next && fast->next->next){
slow=slow->next;
fast=fast->next->next;
if(slow==fast){
    cout<<"LOOP and value at that node is: "<<slow->data<<" "<<fast->data<<endl;
    return;
}
}
cout<<"NO LOOP"<<endl;
}
void pali(Node*head){
Node*slow=head;
Node*fast=head;
Node*init=head;
while(fast->next && fast->next->next){
    slow=slow->next;
    fast=fast->next->next;
}
Node*check=slow;
Node*rev=reverse(slow);
while(init && rev){
if(init->data!=rev->data){
    cout<<"Not a palindrome"<<endl;
    return;
}
init=init->next;
rev=rev->next;
}
cout<<"PALI"<<endl;
}
Node*OddEven(Node*head){
Node*odd=head;
Node*even=head->next;
Node*fin=even;
while(even->next && even->next->next){
odd->next=odd->next->next;
even->next=even->next->next;
odd=odd->next;
even=even->next;
}
odd->next=fin;
return head;
}
Node*delKfromLast(Node*head,int k){
Node*temp=head;
Node*sec=head;
for(int i=0;i<k;i++){
    temp=temp->next;
}
while(temp->next){
    sec=sec->next;
    temp=temp->next;
}
Node*delnode=sec->next;
sec->next=sec->next->next;
delete delnode;
return head;
}
};
int main(){
Node *l=new Node(1);
l->next=new Node(2);
l->next->next=new Node(3);
l->next->next->next=new Node(4);
l->next->next->next->next=new Node(5);
l->next->next->next->next->next=new Node(6);
// l->delKfromLast(l,6);
l->print(l);
// l=l->insert(l,69,5);
// l=l->insert(l,36,3);
// l=l->insert(l,30,1);
//l=l->del(l,5);
// l->print(l);
//l->search(l,2);
// l->middle(l);
// Node*q=l->reverse(l);
// cout<<"Reversed: "<<endl;
// q->print(q);
// q->next->next->next->next=new Node(100,q->next);
// l->detectloop(l);
// Node*oddeve=l->OddEven(l);
// oddeve->print(oddeve);
//l->pali(l);
}