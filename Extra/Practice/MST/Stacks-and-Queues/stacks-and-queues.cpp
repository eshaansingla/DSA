#include <iostream>
using namespace std;
class stack
{
public:
    int arr[100];
    int Top = -1;
    void push(int data)
    {
        if (Top == ((sizeof(arr) / sizeof(arr[0])) - 1))
            cout << "Overflow" << endl;
        else
            arr[++Top] = data;
    }
    void pop()
    {
        if (Top == -1)
            cout << "Underflow" << endl;
        else
            Top--;
    }
    void top()
    {
        cout << arr[Top] << endl;
    }
    void isempty()
    {
        if (Top == -1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
};
class queue
{
public:
    int arr[3];
    int start = -1;
    int end = -1;
    int size = 0;
    void push(int data)
    {

        if (start == -1)
            start++;
        if (end == ((sizeof(arr) / sizeof(arr[0])) - 1))
        {
            end = (end + 1) % (sizeof(arr) / sizeof(arr[0]));
            arr[end] = data;
        }
        else
        {
            arr[++end] = data;
        }
        size++;
    }
    void pop()
    {
        if (start == -1)
            cout << "Underflow" << endl;
        else
            start++;
        if (start == ((sizeof(arr) / sizeof(arr[0])) - 1))
        {
            start = (start + 1) % (sizeof(arr) / sizeof(arr[0]));
        }
        size--;
    }
    void top()
    {
        cout << arr[start] << endl;
    }
    void isempty()
    {
        if (end == -1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
};
int main()
{
    // stack st;
    // st.isempty();
    // st.pop();
    // st.push(2);
    // st.push(5);
    // st.push(1);
    // st.push(4);
    // st.top();
    // st.pop();
    // st.top();
    // st.isempty();
    queue q;
    q.isempty();
    q.pop();
    q.push(2);
    q.push(5);
    q.push(1);
    q.push(4);
    q.push(10);
    q.push(7);
    q.top();
    q.pop();
    q.top();
    q.pop();
    q.top();
    q.isempty();
}