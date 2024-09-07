/*
unlike arrays the elements are not contiguous 
the elements of linked lists lie randomly in heap and can be excessed if the location of that element is known.
linked like: head->next->next->next->tail(next==NULL)
              1st   2nd   3rd   4th   5th
*/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data, Node*next){
        this->data=data;
        (*this).next=next;
    }
    Node(int data){
        this->data=data;
    }
};
Node* LL(vector<int>&arr){
        Node *head=new Node(arr[0]);
        Node *mover=head;
        for(int i=0;i<arr.size();i++){
            Node*temp= new Node(arr[i]);
            mover->next=temp;
            mover=temp;
        }
        return head;
    }
int main(){
    vector<int>arr={1,5,2,3,4,6,7,10,8,9};
    Node*head=LL(arr);
    cout<<head->data;
    }