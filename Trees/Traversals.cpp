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
void preorderIterative(Node*root){
    stack<Node*>st;
    vector<int>ans;
    if(!root) return;
    else if(root) st.push(root);
    while(!st.empty()){
        Node*temp=st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
    for(auto it:ans) cout<<it<<" ";
}
 vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>saul;
        queue<Node*>q;
        if(root){
            q.push(root);
        }
        while(!q.empty()){
            vector<int>out;
            int s=q.size();
            for(int i=0;i<s;i++){
                Node*temp=q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                out.push_back(temp->data);
                q.pop();
            }
            saul.push_back(out);
        }
        return saul;
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
preorder(root);
cout<<endl;
inorder(root);
cout<<endl;
postorder(root);
cout<<endl;
vector<vector<int>>v=levelOrder(root);
int i=0;
for(auto it:v){
    for(auto it1:it){
        cout<<it1<<" ";
    }
    cout<<endl;
}
preorderIterative(root);
}
