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
bool checkBST(Node*root,long long minvl,long long maxvl){
if(!root) return true;
if(root->data<=minvl || root->data>=maxvl) return false;
return checkBST(root->left,minvl,root->data) && checkBST(root->right,root->data,maxvl);
}
Node* intoBSTHelper(vector<int>& nums, int low, int high) {
    if (low > high) return nullptr;
    int mid = low + (high - low) / 2;
    Node* root = new Node(nums[mid]);
    root->left = intoBSTHelper(nums, low, mid - 1);  // Recursively build left subtree
    root->right = intoBSTHelper(nums, mid + 1, high);  // Recursively build right subtree
    return root;
}
void Heapify(vector<int>&arr,int n,int i){
int largest=i;
int left=2*i;
int right=2*i+1;
if(arr[left]<arr[largest] && left<=n) largest=left;
if(arr[right]<arr[largest] && right<=n) largest=right;
if(i!=largest){
    swap(arr[i],arr[largest]);
    Heapify(arr,n,largest);
}
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
//print(Tree);
//minmaxval(Tree);
Tree=deletefromBST(Tree,9);
cout<<"**********"<<endl;
//print(Tree);
vector<int>nums={10,20,30,100,150,200,300};
Node*inord=intoBSTHelper(nums,0,6);
//print(inord);
vector<int>arr={-1,56,55,57,59,60,58,61,62};
int n=arr.size();
for(int i=(n-1)/2;i>0;i--){
    swap(arr[0],arr[i]);
     Heapify(arr,n,i);
     }
for(int i=1;i<n;i++) cout<<arr[i]<<endl;
}