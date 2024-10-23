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
int maxDepth(Node* root) {
        if(!root) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        return 1+max(l,r);
    }
int diameter(Node* root,int &maxi){
        if(!root) return 0;
        int lh=diameter(root->left,maxi);
        int rh=diameter(root->right,maxi);
        maxi = max(maxi, lh + rh);
        return 1+max(lh,rh);
    }
void diameterOfBinaryTree(Node* root){
        int maxi=0;
        if(!root) return;
        diameter(root,maxi);
        cout<< maxi;
    }
int check(Node*root){
        if(!root) return 0;
        int lh=check(root->left);
        if(lh==-1) return -1;
        int rh=check(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
void isBalanced(Node* root) {
        if(check(root)!=-1) cout<<"Balanced"<<endl;
        else cout<<"Not Balanced"<<endl;
    }
int calculate(Node*root,int &maxi){
        if(!root){
            return 0;
        }
        int lv=max(0,calculate(root->left,maxi));
        int rv=max(0,calculate(root->right,maxi));
        maxi=max(maxi,root->data+lv+rv);
        return root->data+max(lv,rv);
    }
int maxPathSum(Node* root) {
        int maxi=INT_MIN;
        calculate(root,maxi);
        return maxi;
    }
bool isSameTree(Node* p, Node* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return (p->data==q->data) 
        && isSameTree(p->left,q->left) 
        && isSameTree(p->right,q->right);
    }
vector<vector<int>> zigzagLevelOrder(Node* root) {
        vector<vector<int>>saul;
        queue<Node*>q;
        if(root){
            q.push(root);
        }
        bool flag=0;
        while(!q.empty()){
            int s=q.size();
            vector<int>out;
            for(int i=0;i<s;i++){
                Node*temp=q.front();
                out.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                q.pop();
            }
        if(flag){
            reverse(out.begin(),out.end());
        }
        saul.emplace_back(out);
        flag = !flag;
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
cout<<maxDepth(root)<<endl;
isBalanced(root);
diameterOfBinaryTree(root);
cout<<endl;
cout<<maxPathSum(root)<<endl;
cout<<isSameTree(root,root)<<endl<<endl;
vector<vector<int>>v=zigzagLevelOrder(root);
for(auto it:v){
    for(auto it1:it){
        cout<<it1<<" ";
    }
    cout<<endl;
}
}