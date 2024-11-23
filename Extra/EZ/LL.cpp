//LESS GOOOOOO
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
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
        cout<<endl;
    }
};
Node*insert(Node*head,int k,int l){
if(!head) return new Node(l);
Node*temp=head;
while(temp){
if(temp->data==k){
temp->next=new Node(l,temp->next);
break;
}
temp=temp->next;
}
return head;
}
Node*del(Node*head,int k){
if(head->data==k && !head->next) return nullptr;
if(head->data==k && head->next){
    Node*delnode=head;
    head=head->next;
    delete delnode;
    return head;
}
Node*temp=head;
Node*delnode;
while(temp){
    if(temp->next->data==k){
        delnode=temp->next;
        temp->next=temp->next->next;
        delete delnode;
        break;
    }
    temp=temp->next;
}
return head;
}
void middle(Node*head){
if(!head) return;
Node*slow=head;
Node*fast=head;
while(fast->next && fast->next->next){
    slow=slow->next;
    fast=fast->next->next;
}
cout<<slow->data<<endl;
}
Node* reverse(Node*head){
       Node*prev=nullptr;
       Node*temp=head;
       while(temp){
           Node*front=temp->next;
           temp->next=prev;
           prev=temp;
           temp=front;
       }
       return prev;
   }
void loop(Node*head){
    Node*slow=head;
    Node*fast=head;
    bool flag=0;
    while(fast->next and fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){ 
            flag=1;
            break;
            }
    }
    fast=fast->next;
    int cnt=1;
    if(flag){
        while(slow!=fast){
        cnt++;
        fast=fast->next;
        }
         cout<<"loop"<<" and the length is: "<<cnt<<endl;
         }
    else cout<<"No Loop"<<endl;
}
int main(){
Node*p=new Node(6);
p->next=new Node(9);
p->next->next=new Node(4);
p->next->next->next=new Node(2);
p->next->next->next->next=new Node(0);
p->next->next->next->next->next=new Node(69420,p->next->next);
//p=insert(p,9,0);
//p->print(p);
/*
Node*q=new Node(6);
q=insert(q,6,9);
q->print(q);
q=del(q,6);
q->print(q);
Node*r=new Node(6);
r=del(r,6);
r->print(r);
*/
//p->print(p);
loop(p);
}