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
bool isleaf(Node*root){
return root && !root->left && !root->right;
}
void addleft(Node*root,vector<int>&res){
    root=root->left;
    if(!root) return;
    if(!isleaf(root)) res.emplace_back(root->data);
    if(root->left) addleft(root->left,res);
    else addleft(root->right,res);
}
void addright(Node*root,vector<int>&res){
    if(!root) return;
    vector<int>temp;
    if(!isleaf(root)) temp.emplace_back(root->data);
    if(root->right) addright(root->right,temp);
    else if(root->left) addright(root->left,temp);
    reverse(temp.begin(),temp.end());
    for(auto it:temp){
        res.emplace_back(it);
    }
}
void addleaves(Node*root,vector<int>&res){
    if(isleaf(root)){ 
        res.emplace_back(root->data);
        return;
    }
    if(root->left) addleaves(root->left,res);
    if(root->right) addleaves(root->right,res);
}
void doit(Node*root,vector<int>&res){
    if(!root) return;
    if(!isleaf(root)) res.emplace_back(root->data);
    addleft(root,res);
    addleaves(root,res);
    addright(root,res);
    res.pop_back();
    for(auto it: res) cout<<(it)<<" ";
}
void VerticalOrder(Node*root){
    map<int,map<int,multiset<int>>>mpp;
    queue<pair<Node*,pair<int,int>>>todo;
    if(root) todo.push({root,{0,0}});
    vector<vector<int>>saul;
    while(!todo.empty()){
        pair<Node*,pair<int,int>>t=todo.front();
        todo.pop();
        Node*p=t.first;
        int x=t.second.first;
        int y=t.second.second;
        mpp[x][y].insert(p->data);
        if(p->left) todo.push({p->left,{x-1,y+1}});
        if(p->right) todo.push({p->right,{x+1,y+1}});
    }
     for(auto it:mpp){
            vector<int>col;
            for(auto j:it.second){
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            saul.emplace_back(col);
        }
    for(auto &it:saul){
        for(auto &it1:it){
           cout<<it1<<" ";
        }
        cout<<endl;
    }
}
void top_view(Node*root){
    vector<int>sol;
    queue<pair<Node*,int>>todo;
    map<int,int>mpp;
    if(root) todo.push({root,0});
    while(!todo.empty()){
        auto it=todo.front();
        todo.pop();
        Node*l=it.first;
        int line=it.second;
        if(mpp.find(line)==mpp.end()) mpp[line]=l->data;
        if(l->left) todo.push({l->left,line-1});
        if(l->right) todo.push({l->right,line+1});
    }
    for(auto it:mpp) cout<<it.second<<" ";
}
void bottom_view(Node*root){
    map<int,int>mpp;
    queue<pair<Node*,int>>task;
    if(root) task.push({root,0});
    while(!task.empty()){
        auto j=task.front();
        task.pop();
        Node*p=j.first;
        int line=j.second;
        mpp[line]=p->data;
        if(p->left) task.push({p->left,line-1});
        if(p->right) task.push({p->right,line+1});
    }
    for(auto it:mpp) cout<<it.second<<" ";
}
void right_view(Node*root){
    map<int,int>mpp;
    queue<pair<Node*,int>>q;
    if(root) q.push({root,0});
    while(!q.empty()){
        auto e=q.front();
        q.pop();
        Node*p=e.first;
        int g=e.second;
        mpp[g]=p->data;
        if(p->left) q.push({p->left,g+1});
        if(p->right) q.push({p->right,g+1});
    }
        for(auto it:mpp) cout<<it.second<<" ";
    }
void left_view(Node*root){
    queue<pair<Node*,int>>list;
    map<int,int>mpp;
    if(root) list.push({root,0});
    while(!list.empty()){
        auto k=list.front();
        list.pop();
        Node*p=k.first;
        int l=k.second;
        if(mpp.find(l)==mpp.end()) mpp[l]=p->data;
        if(p->left) list.push({p->left,l+1});
        if(p->right) list.push({p->right,l+1});
    }
    for(auto it:mpp){
        cout<<it.second<<" ";
    }
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
    /*Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);*/
    vector<int>res;
    doit(root,res);
    cout<<endl;
    VerticalOrder(root);
    top_view(root);
    cout<<endl;
    bottom_view(root);
    cout<<endl;
    right_view(root);
    cout<<endl;
    left_view(root);
}