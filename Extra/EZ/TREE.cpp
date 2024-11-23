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
void minmaxval(Node*root){
    Node*temp=root;
    Node*temp1=root;
    while(temp->left){
        temp=temp->left;
    }
    while(temp1->right){
        temp1=temp1->right;
    }
    cout<<temp->data<<" "<<temp1->data<<endl;
}
void print(Node*root){
    vector<vector<int>>saul;
    queue<Node*>q;
    if(root) q.push(root);
    while(!q.empty()){
        int l=q.size();
        vector<int>out;
        for(int i=0;i<l;i++){
            auto front=q.front();
            q.pop();
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
            out.emplace_back(front->data);
        }
        saul.emplace_back(out);
    }
    for(auto it:saul){
        for(auto it1:it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}
int minval(Node*root){
    while(root->left) root=root->left;
    return root->data;
}
Node*insert(Node*head,int data){
    if(!head){
        return new Node(data);
    }
    if(data>head->data){
        head->right=insert(head->right,data);
    }
    if(data<head->data){
    head->left=insert(head->left,data);
    }
    return head;
}
Node*deletefromBST(Node*root,int val){
if(!root) return root;
if(root->data==val){
// 0 
if(!root->left and !root->right){
    Node*del=root;
    delete del;
    return nullptr;
}
// 1
if(root->left and !root->right){
    Node*del=root;
    root=root->left;
    delete del;
    return root;
}
if(!root->left and root->right){
    Node*del=root;
    root=root->right;
    delete del;
    return root;
}
// 2
if(root->left and root->right){
    int mini=minval(root->right);
    root->data=mini;
    root->right=deletefromBST(root->right,mini);
}
}
else if(root->data>val){
    root->left=deletefromBST(root->left,val);
}
else root->right=deletefromBST(root->right,val);
}
int main(){
Node*Tree=nullptr;
Tree=insert(Tree,6);
Tree=insert(Tree,9);
Tree=insert(Tree,11);
Tree=insert(Tree,8);
Tree=insert(Tree,4);
Tree=insert(Tree,2);
Tree=insert(Tree,0);
print(Tree);
//minmaxval(Tree);
Tree=deletefromBST(Tree,9);
cout<<"**********"<<endl;
print(Tree);
}