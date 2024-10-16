#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node*left;
Node*right;
Node(int data){
    this->data=data;
    this->left=nullptr;
    this->right=nullptr;
}
};
void preorder(Node*head){
    if(head==nullptr) return;
    cout<<head->data<<" ";
    preorder(head->left);
    preorder(head->right);
}
void postorder(Node*head){
    if(head==nullptr) return;
    postorder(head->left);
    postorder(head->right);
    cout<<head->data<<" ";
}
void inorder(Node*head){
    if(head==nullptr) return;
    inorder(head->left);
    cout<<head->data<<" ";
    inorder(head->right);
}
int main(){
Node*root=new Node(1);
root->left=new Node(2);
root->right=new Node(3);
root->left->left=new Node(4);
root->left->right=new Node(5);
root->left->right->left=new Node(6);
root->right->left=new Node(7);
root->right->right=new Node(8);
root->right->right->left=new Node(9);
root->right->right->right=new Node(10);
inorder(root);
}
