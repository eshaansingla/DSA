#include<bits/stdc++.h>
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
    Node* deleteHead(Node*head){
       Node *temp=head;
       head=head->next;
       delete temp;
       //cout<<head->data<<endl;
       return head;
    }
};
int main(){
    int arr[]={2,3,4,5};
    Node* head = new Node(arr[0],new Node(arr[1]));
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head =(*head).deleteHead(head);
    while(head!=nullptr){
        cout<<head->data<<endl;
        head=head->next;
    }
}