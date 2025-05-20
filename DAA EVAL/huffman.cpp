#include <bits/stdc++.h>
using namespace std;
class Huffman
{
public:
    int ch;
    int freq;
    Huffman *left;
    Huffman *right;
    Huffman(int ch, int freq)
    {
        this->ch = ch;
        this->freq = freq;
        this->left = nullptr;
        this->right = nullptr;
    }
};
struct Compare
{
    bool operator()(const Huffman *a, const Huffman *b)
    {
        return a->freq > b->freq;
    }
};
void encode(Huffman *root, string code, unordered_map<char, string> &mpp)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        mpp[root->ch] = code;
    }
    encode(root->left, code + "0", mpp);
    encode(root->right, code + "1", mpp);
}
string decode(Huffman *root, string &encoded)
{
    string decoded = "";
    Huffman *cur = root;
    for (char it : encoded)
    {
        if (it == '0')
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
        if (!cur->left && !cur->right)
        {
            decoded += cur->ch;
            cur = root;
        }
    }
    return decoded;
}
int main()
{
    string input = "eshaan singla";
    unordered_map<char, int> mpp;
    for (auto it : input)
    {
        mpp[it]++;
    }
    priority_queue<Huffman *, vector<Huffman *>, Compare> pq;
    for (auto it : mpp)
    {
        pq.push(new Huffman(it.first, it.second));
    }
    while (pq.size() > 1)
    {
        Huffman *left = pq.top();
        pq.pop();
        Huffman *right = pq.top();
        pq.pop();
        Huffman *merged = new Huffman('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }
    Huffman *root = pq.top();
    unordered_map<char, string> encoder;
    encode(root, "", encoder);
    string bin_word = "";
    for (auto it : input)
    {
        bin_word += encoder[it];
    }
    string decoded = decode(root, bin_word);
    cout << decoded << endl;
}
