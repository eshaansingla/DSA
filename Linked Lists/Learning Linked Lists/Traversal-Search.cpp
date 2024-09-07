#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
    }
    Node(int data,Node*next){
        this->data=data;
        this->next=next;
    }
    Node* add(int *a,int size){
        Node *head= new Node(a[0]);
        Node *mover=head;
        int i=0;
        while(i<size){
            Node *temp=new Node(a[i]);
            mover->next=temp;
            mover=temp;
            cout<<mover->data<<endl;
            i++;
        }
        return head;
    }
    int search(int *a,int size,int search){
        Node *head=new Node(a[0]);
        Node *mover=head;
        for(int i=0;i<size;i++){
            Node *temp=new Node(a[i]);
            mover->next=temp;
            mover=temp;
            if(mover->data==search) return i;
        }
        return -1;
    }
};
int main(){
    int arr[]={2,3,1,5,7,6,3,5,7,8};
    Node *n=new Node(arr[0]);
    int m=sizeof(arr)/sizeof(arr[0]);
    cout<<(*n).add(arr,m)<<endl;
    int l=6;
    cout<<(*n).search(arr,m,l)<<endl;
}