#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
Node *insertbegin(Node *head, int k)
{
    return new Node(k, head);
}
Node *insertback(Node *head, int k)
{
    if (head == nullptr)
        return new Node(k);
    Node *temp = head;
    while (temp)
    {
        if (temp->next == nullptr)
        {
            Node *x = new Node(k);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node *insert(Node *head, int k, int put)
{
    if (head == nullptr)
        return new Node(k);
    Node *temp = head;
    while (temp)
    {
        if (temp->data == k)
        {
            Node *x = new Node(put, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
Node *deletebegin(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is already empty!" << endl;
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
Node *deleteend(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is already empty!" << endl;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {
        if (temp->next == nullptr)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node *del(Node *head, int k)
{
    if (head == nullptr)
    {
        cout << "List is already empty!" << endl;
        return head;
    }
    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {
        if (temp->data == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int find(Node *head, int k)
{
    if (head == nullptr)
    {
        cout << "List is already empty!" << endl;
        return -1;
    }
    Node *mover = head;
    int cnt = 0;
    while (mover)
    {
        if (mover->data == k)
        {
            return cnt;
        }
        cnt++;
        mover = mover->next;
    }
    return -1;
}
void print(Node *p)
{
    Node *mover = p;
    while (mover)
    {
        cout << mover->data << endl;
        mover = mover->next;
    }
}
int main()
{
    int arr[5];
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        cout << "Enter a number:";
        cin >> arr[i];
    }
    Node *p = new Node(arr[0]);
    p->next = new Node(arr[1]);
    p->next->next = new Node(arr[2]);
    p->next->next->next = new Node(arr[3]);
    p->next->next->next->next = new Node(arr[4]);
    int ch;
    while (true)
    {
        cout << "Menu:" << endl
             << endl;
        cout << "1.Insert at beginning." << endl;
        cout << "2.Insert at end." << endl;
        cout << "3.Insert at after any element." << endl;
        cout << "4.Delete begin." << endl;
        cout << "5.Delete end." << endl;
        cout << "6.Delete any element." << endl;
        cout << "7.Find an element." << endl;
        cout << "8.Display LinkedList." << endl
             << endl;
        cout << "Enter choice:";
        cin >> ch;
        int k;
        switch (ch)
        {
        case 1:
            cout << "Enter k:";
            cin >> k;
            p = insertbegin(p, k);
            break;
        case 2:
            cout << "Enter k:";
            cin >> k;
            p = insertback(p, k);
            break;
        case 3:
            cout << "Enter k:";
            cin >> k;
            int l;
            cout << "Enter Number:";
            cin >> l;
            p = insert(p, k, l);
            break;
        case 4:
            p = deletebegin(p);
            break;
        case 5:
            p = deleteend(p);
            break;
        case 6:
            cout << "Enter k:";
            cin >> k;
            p = del(p, k);
            break;
        case 7:
            cout << "Enter k:";
            cin >> k;
            cout << "The index is: " << find(p, k) << endl;
            break;
        case 8:
            print(p);
            break;
        default:
            cout << "Enter valid input" << endl;
            break;
        }
    }
}