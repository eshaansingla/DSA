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
    Node*deletehead(Node*head){
        Node*temp=head;
        while(temp->next!=head) temp=temp->next;
        temp->next=head->next;
        head=head->next;
        return head;
    }
    Node* makecircular(Node*head){
        Node*temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        return head;
    }
    void print(Node*head){
        Node*temp=head;
        do{
            cout<<temp->data<<endl;
            temp=temp->next;
        }while(temp!=head);
    }
    Node*inserthead(Node*head,int val){
        Node*n=new Node(val,head);
        Node*temp=head;
        while(temp->next!=head) temp=temp->next;
        temp->next=n;
        head=n;
        return head;
    }
};
int main(){
Node*p= new Node(2);
p->next=new Node(3);
p->next->next=new Node(1);
p->next->next->next=new Node(6);
p->next->next->next->next=new Node(4);
p->next->next->next->next->next=new Node(5);
p=p->makecircular(p);
p=p->deletehead(p);
p=p->inserthead(p,69);
p->print(p);
}