#include <iostream>
using namespace std;
class ListNode
{

public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        this->val = data;
        this->next = nullptr;
    }
    ListNode(int data, ListNode *next)
    {
        this->val = data;
        this->next = next;
    }
};
ListNode *rever(ListNode *head)
{
    ListNode *temp = head;
    ListNode *front = nullptr;
    ListNode *prev = nullptr;
    while (temp)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
    cout << "X";
    return;
}
ListNode *alternate(ListNode *head)
{
}
int main()
{
    ListNode *a = new ListNode(0);
    a->next = new ListNode(1);
    a->next->next = new ListNode(2);
    a->next->next->next = new ListNode(3);
    a->next->next->next->next = new ListNode(4);
    a->next->next->next->next->next = new ListNode(5);
    a->next->next->next->next->next->next = new ListNode(6);
    a->next->next->next->next->next->next->next = new ListNode(7);
    // print(a);
    // ListNode *rev_a = rever(a);
    // cout << endl;
    // print(rev_a);
}