#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*right;
    Node*left;
    Node(int data){
        this->data=data;
        this->left=nullptr;
        this->right=nullptr;
    }
};
void inorder(Node*root,vector<int>&sol){
if(!root) return;
inorder(root->left,sol);
sol.emplace_back(root->data);
inorder(root->right,sol);
}
void postorder(Node*root,vector<int>&sol){
if(!root) return;
postorder(root->left,sol);
postorder(root->right,sol);
sol.emplace_back(root->data);
}
void preorder(Node*root,vector<int>&sol){
if(!root) return;
sol.emplace_back(root->data);
preorder(root->left,sol);
preorder(root->right,sol);
}
vector<vector<int>> levelOrder(Node*root){
vector<vector<int>>saul;
queue<Node*>q;
if(root) q.push(root);
while(!q.empty()){
    vector<int>ans;
    int l=q.size();
    for(int i=0;i<l;i++){
        auto temp=q.front();
        q.pop();
        ans.emplace_back(temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    saul.emplace_back(ans);
}
return saul;
}
int LeafNodes(Node*root,int &number){
if(!root->left && !root->right) number++;
if(root->left) LeafNodes(root->left,number);
if(root->right) LeafNodes(root->right,number);
return number;
}
int Height(Node*root){
if(!root) return 0;
int lh=Height(root->left);
int rh=Height(root->right);
return 1+max(lh,rh);
}
int Diameter(Node*root,int &m){
    if(!root) return 0;
    int lh=Diameter(root->left,m);
    int rh=Diameter(root->right,m);
    m=max(m,lh+rh);
    return 1+max(lh,rh);
}
int checkBalanced(Node*root){
if(!root) return 0;
int lh=checkBalanced(root->left);
if(lh==-1) return -1;
int rh=checkBalanced(root->right);
if(rh==-1) return -1;
if(abs(lh-rh)>1) return -1;
return 1+max(lh,rh);
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
// root->right->right->right->right=new Node(10);
// root->right->right->right->right->right=new Node(10);
// root->right->right->right->right->right->right=new Node(10);
// vector<int>sol;
// vector<int>sol1;
// vector<int>sol2;
// preorder(root,sol);
// inorder(root,sol1);
// postorder(root,sol2);
// for(auto it:sol) cout<<it<<" ";
// cout<<endl;
// for(auto it:sol1) cout<<it<<" ";
// cout<<endl;
// for(auto it:sol2) cout<<it<<" ";
// vector<vector<int>>sol=levelOrder(root);
// for(auto it:sol){
// for(auto it1:it){
//     cout<<it1<<" ";
// }
// cout<<endl;
// }
// int num=0;
// cout<<LeafNodes(root,num)<<endl;
// cout<<Height(root)<<endl;
int maxi=INT_MIN;
Diameter(root,maxi);
cout<<maxi<<endl;
if(checkBalanced(root)!=-1){
    cout<<"Balanced"<<endl;
}
else cout<<"NAH";
}