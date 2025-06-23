#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node()
    {
        this->left = nullptr;
        this->right = nullptr;
    }
    Node(int val, Node *left, Node *right)
    {
        this->val = val;
        this->left = left;
        this->right = right;
    }
    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void levelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> sol;
    while (!q.empty())
    {
        vector<int> ans;
        int l = q.size();
        for (int i = 0; i < l; i++)
        {
            auto fnt = q.front();
            q.pop();
            ans.emplace_back(fnt->val);
            if (fnt->left)
                q.push(fnt->left);
            if (fnt->right)
                q.push(fnt->right);
        }
        sol.push_back(ans);
    }
    for (auto it : sol)
    {
        for (auto it1 : it)
            cout << it1 << " ";
        cout << endl;
    }
}
void inorder(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
void leafNodes(Node *root, int &cnt)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        cnt++;
    leafNodes(root->left, cnt);
    leafNodes(root->right, cnt);
}
int depth(Node *root)
{
    if (!root)
        return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    return max(left, right) + 1;
}
bool balancedTree(Node *root)
{
    if (!root)
        return true;
    bool left = balancedTree(root->left);
    bool right = balancedTree(root->right);
    bool diff = abs(depth(root->left) - depth(root->right)) <= 1;
    if (left && right && diff)
        return true;
    else
        return false;
}
int sums(Node *root, bool &ans)
{
    if (!root || !ans)
        return 0;
    if (!root->left && !root->right)
        return root->val;
    int left = sums(root->left, ans);
    int right = sums(root->right, ans);
    if (left + right != root->val)
        ans = false;
    return left + right + root->val;
}
vector<vector<int>> zigzag(Node *root)
{
    if (!root)
        return {};
    queue<Node *> q;
    vector<vector<int>> sol;
    q.push(root);
    bool odd = 0;
    while (!q.empty())
    {
        int l = q.size();
        vector<int> temp;
        while (l--)
        {
            auto fnt = q.front();
            q.pop();
            temp.push_back(fnt->val);
            if (fnt->left)
                q.push(fnt->left);
            if (fnt->right)
                q.push(fnt->right);
        }
        if (odd)
        {
            reverse(temp.begin(), temp.end());
        }
        odd = !odd;
        sol.push_back(temp);
    }
    return sol;
}
int main()
{
    Node *p = new Node(44);
    p->left = new Node(18);
    p->right = new Node(26);
    p->left->left = new Node(8);
    p->left->right = new Node(10);
    p->left->left->left = new Node(0);
    p->left->left->right = new Node(8);
    p->left->right->left = new Node(4);
    p->left->right->right = new Node(6);
    p->right->left = new Node(11);
    p->right->right = new Node(15);
    p->right->left->left = new Node(5);
    p->right->left->right = new Node(6);
    p->right->right->left = new Node(7);
    p->right->right->right = new Node(8);
    levelOrder(p);
    cout << endl;
    vector<int> ans;
    inorder(p, ans);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    int a = 0;
    leafNodes(p, a);
    cout << a << endl;
    cout << depth(p) << endl;
    cout << balancedTree(p) << endl;
    bool b = true;
    sums(p, b);
    cout << b << endl;
    cout << endl;
    vector<vector<int>> zig = zigzag(p);
    for (auto it : zig)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
}