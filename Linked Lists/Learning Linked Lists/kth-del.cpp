#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
    Node(int data,Node *next){
        this->data=data;
        this->next=next;
    }
};
Node* delHead(Node *head){
Node *temp=head;
head=head->next;
delete temp;
return head;
}
int main(){
    int arr[]={2,5,8,9,10};
    Node *head=new Node(arr[0]);
    head->next=new Node(arr[1]);
    head->next->next=new Node(arr[2]);
    head->next->next->next=new Node(arr[3]);
    head->next->next->next->next=new Node(arr[4]);
    head=delHead(head);
    Node *mover = head;
    while (mover != nullptr) {
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}