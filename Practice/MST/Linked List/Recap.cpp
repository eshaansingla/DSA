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
    string search(int k,Node*head){
        Node*temp=head;
        while(temp){
            if(temp->data==k){
                 return "Found :)";
            }
            temp=temp->next;
        }
        return "Not Found :(";
    }
    Node* del(Node*head,int k){
         Node*temp=head;
         Node*prev=nullptr;
        if(k==head->data) return new Node(head->next->data,head->next->next);
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
    Node* insert(Node*head,int k,int l){
        Node*temp=head;
        if(temp->data==k){
        return new Node(l,head);
        }
        while(temp){
            if(temp->data==k){
                temp->next=new Node(l,temp->next);
                break;
            }
            temp=temp->next;
        }
        return head;
    }
    void middle(Node*head){
        Node*slow=head;
        Node*fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        cout<<"Middle is: "<<slow->data<<endl;
    }
};
int main(){
Node*p=new Node(5);
p->next=new Node(2);
p->next->next=new Node(3);
p->next->next->next=new Node(4);
p->next->next->next->next=new Node(1);
p->next->next->next->next->next=new Node(9);
p->print(p);
cout<<endl;
cout<<p->search(6,p)<<endl;
cout<<p->search(9,p)<<endl;
p=p->del(p,5);
p->print(p);
cout<<endl;
p=p->insert(p,9,4);
p->print(p);
p->middle(p);
}