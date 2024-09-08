#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
    Node(int data,Node*next){
        this->data=data;
        this->next=next;
    }
};
Node* del(Node *head,int k){
if(k==2){
    Node*temp=head;
    head=head->next;
    free(temp);
    return head;
}
else{
    Node*temp=head;
    Node*prev=nullptr;
    while(temp){
        if(k==temp->data){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
}
Node*inserting(Node*head,int k){
return new Node(k,head);
}
Node*insertk(Node*head,int k,int ind){
if(head==nullptr) return new Node(k);
int cnt=0;
Node*temp=head;
while(temp){
cnt++;
if(cnt==ind-1){
Node *x= new Node(k,temp->next);
temp->next=x;
break;
}
temp=temp->next;
}
return head;
}
Node *insertbefore(Node*head,int val,int add){
if(head==nullptr) return new Node(add);
Node*temp=head;
while(temp->next){
if(temp->next->data==val){
Node *x= new Node(add,temp->next);
temp->next=x;
break;
}
temp=temp->next;
}
return head;
}
int main(){
int arr[]={2,5,8,9,10};
Node *head=new Node(arr[0]);
head->next=new Node(arr[1]);
head->next->next=new Node(arr[2]);
head->next->next->next=new Node(arr[3]);
head->next->next->next->next=new Node(arr[4]);
head=inserting(head,20);
head=insertk(head,36,2);
head=insertbefore(head,69,12504);
Node*mover=head;
while(mover){
    cout<<mover->data<<endl;
    mover=mover->next;
}
}