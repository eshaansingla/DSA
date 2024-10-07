#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*back;
    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->back=nullptr;
    }
    Node(int data,Node*next,Node*back){
        this->data=data;
        this->next=next;
        this->back=back;
    }
    void print(Node*head){
        Node*temp=head;
        while(temp){
            cout<<temp->data<<endl;
            temp=temp->back;
        }
    }
    ~Node(){
        delete next;
        delete back;
    }
};
int main(){
vector<int>arr={5,3,4,2,7,9,8};
Node*p=new Node(arr[0]);
Node*prev=p;
for(int i=1;i<arr.size();i++){
    Node*temp=new Node(arr[i],nullptr,prev);
    prev->next=temp;
    prev=temp;
}
p->print(prev);
}