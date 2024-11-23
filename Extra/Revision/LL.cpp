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
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void printc(Node*head){
    Node*temp=head;
do{
    cout<<temp->data<<endl;
    temp=temp->next;
}while(temp!=head);
}
Node*makecircular(Node* head){
    Node*temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=head;
    return head;
}
Node*insert(Node*head,int k,int l){
    Node*temp=head;
    if(head->data==k){
        return new Node(l,head);
    }
    while(temp){
        if(temp->next->data==k){
            temp->next=new Node(l,temp->next);
            break;
        }
        temp=temp->next;
    }
    return head;
}
Node*del(Node*head,int k){
Node*temp=head;
Node*prev=nullptr;
if(head->data==k){
    return new Node(head->next->data,head->next->next);
}
while(temp){
    if(temp->data==k){
        prev->next=temp->next;
        delete temp;
        break;
    }
    prev=temp;
    temp=temp->next;
}
return head;
}
int Detectloop(Node*head){
    int t=1;
    Node*slow=head;
    Node*fast=head;
    while(fast){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            fast=fast->next;
            while(slow!=fast){
                t++;
                fast=fast->next;
            }
            break;
            }
    }
    return t;
    }
};
int main(){
Node* p=new Node(5);
p->next=new Node(6);
p->next->next=new Node(7);
p->next->next->next=new Node(1);
p->next->next->next->next=new Node(2);
p->next->next->next->next->next=new Node(3);
p->next->next->next->next->next->next=new Node(56,p->next->next);
cout<<endl;
//Node*q=p->makecircular(p);
//p=p->insert(p,2,69);
//p=p->insert(p,5,69);
//p->print(p);
cout<<p->Detectloop(p);
cout<<endl;
}