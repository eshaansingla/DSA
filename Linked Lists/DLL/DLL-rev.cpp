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
};
void print_back(Node*prev){
    Node*temp=prev;
while(temp){
    cout<<temp->data<<" ";
    temp=temp->back;
}
}
int main(){
int n=5;
int arr[n]={3,2,5,1,6};
Node*head=new Node(arr[0]);
Node*prev=head;
for(int i=1;i<n;i++){
Node*temp=new Node(arr[i],nullptr,prev);
prev->next=temp;
prev=temp;
}
print_back(prev);
}