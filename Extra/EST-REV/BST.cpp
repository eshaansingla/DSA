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
    void Insert(Node*&root,int d){
        if(!root){
            root=new Node(d);
            return;
        }
        if(root->data>d){
            Insert(root->left,d);
        }
        else{
           Insert(root->right,d);
        }
    }
};
int Min(Node*root){
while(root->left){
    root=root->left;
}
return root->data;
}
vector<vector<int>> LevelOrder(Node*root){
vector<vector<int>>ans;
queue<Node*>q;
if(root) q.push(root);
while(!q.empty()){
    vector<int>sol;
    int s=q.size();
    for(int i=0;i<s;i++){
        auto fnt=q.front();
        q.pop();
        sol.emplace_back(fnt->data);
        if(fnt->left) q.push(fnt->left);
        if(fnt->right) q.push(fnt->right);
    }
    ans.emplace_back(sol);
}
return ans;
}
void check(Node*root,int d,bool& flag){
    while(root){
        if(root->data==d){ 
            flag=true;
            return;
        }
        else if(root->data>d){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return;
}
Node*del(Node*root,int d){
if(!root) return root;
if(root->data==d){
    
}
}
int Max(Node*root){
while(root->right){
    root=root->right;
}
return root->data;
}
int main(){
Node *root=new Node(6);
root->Insert(root,10);
root->Insert(root,9);
root->Insert(root,4);
root->Insert(root,7);
root->Insert(root,3);
root->Insert(root,5);
root=del(root,4);
root=del(root,7);
root=del(root,3);
vector<vector<int>>saul=LevelOrder(root);
for(auto it:saul){
    for(auto it1:it) cout<<it1<<" ";
    cout<<endl;
}
bool flag=0;
check(root,100,flag);
if(flag) cout<<"Found"<<endl;
else cout<<"Not found"<<endl;
cout<<Min(root)<<" "<<Max(root)<<endl;
}