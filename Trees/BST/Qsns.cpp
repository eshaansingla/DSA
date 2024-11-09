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
Node*search(Node*root,int data){
    if(!root) return root;
    while(root){
        if(root->data==data) return root;
        if(root->data>data) root=root->left;
        else root=root->right;
    }
    return root;
}
int max(Node*root){
    if(!root) return 0;
    while(root->right){
    root=root->right;
    }
    return root->data;
}
int min(Node*root){
    if(!root) return 0;
    while(root->left){
    root=root->left;
    }
    return root->data;
}
int ceil(Node*root,int data){
    if(!root) return 0;
    while(root){
        if(root->data==data){
            data=root->data;
            return data;
        }
        if(root->data>data){
            data=root->data;
            root=root->left;
            }
        else{
            root=root->right;
        }
    }
    return data;
}
int floor(Node*root,int data){
    if(!root) return 0;
    while(root){
        if(root->data==data){
            data=root->data;
            return data;
        }
        if(root->data>data){
            root=root->left;
            }
        else{
            data=root->data;
            root=root->right;
        }
    }
    return data;
}
Node* insertIntoBST(Node* root, int data) {
        Node*sample=root;
        if(!root) return new Node(data);
        while(root){
            if(root->data>=data) {
                if(!root->left){
                    root->left=new Node(data);
                    break;
                }
                root=root->left;
                }
            if(root->data<data){ 
                if(!root->right){
                    root->right=new Node(data);
                    break;
                }
                root=root->right;
            }
        }
        return sample;
    }
int main(){
Node*root=new Node(4);
root->left=new Node(2);
root->right=new Node(7);
root->left->left=new Node(1);
root->left->right=new Node(3);
cout<<search(root,3)->data;
cout<<endl;
cout<<max(root)<<endl;
cout<<min(root)<<endl;
cout<<ceil(root,6)<<endl;
cout<<floor(root,6)<<endl;
cout<<insertIntoBST(root,9)->data<<endl;
}
