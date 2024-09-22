#include <iostream>
#include <string>
using namespace std;
class Stack{
public:
    char arr[100];
    int top;
    int size;
    int tsize;
    Stack()
    {
        top = -1;
        size = 0;
        tsize = 100;
    }
    void push(char x)
    {
        if (top >= tsize - 1)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            arr[++top] = x;
            size++;
        }
    }
    void pop()
    {
        if (top <= -1)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            top--;
            size--;
        }
    }
    int empty()
    {
        if (size <= 0)
            return 1;
        else
            return 0;
    }
    char Top()
    {
        return arr[top];
    }
};
class Stack1{
public:
    string arr[100];
    int top;
    int size;
    int tsize;
    Stack1()
    {
        top = -1;
        size = 0;
        tsize = 100;
    }
    void push(string x)
    {
        if (top >= tsize - 1)
        {
            cout << "Overflow" << endl;
        }
        else
        {
            arr[++top] = x;
            size++;
        }
    }
    void pop()
    {
        if (top <= -1)
        {
            cout << "Underflow" << endl;
        }
        else
        {
            top--;
            size--;
        }
    }
    int empty()
    {
        if (size <= 0)
            return 1;
        else
            return 0;
    }
    string Top()
    {
        return arr[top];
    }
};
int priority(char s){
    if (s == '^')
        return 3;
    else if (s == '*' || s == '/')
        return 2;
    else if (s == '+' || s == '-')
        return 1;
    else
        return -1;
}
string stringrev(string s){
    for (int i = 0; i < (s.length()) / 2; i++)
    {
        char temp = s[i];
        s[i] = s[s.length() - i - 1];
        s[s.length() - i - 1] = temp;
    }
    return s;
}
void inftopost(Stack s, string ch, string ans){
    int i = 0;
    while (i < ch.length())
    {
        if ((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= '0' && ch[i] <= '9'))
        {
            ans = ans + ch[i];
        }
        else if (ch[i] == '(')
        {
            s.push(ch[i]);
        }
        else if (ch[i] == ')')
        {
            while (!s.empty() && s.Top() != '(')
            {
                ans = ans + s.Top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && (priority(ch[i]) <= priority(s.Top())))
            {
                ans = ans + s.Top();
                s.pop();
            }
            s.push(ch[i]);
        }
        i++;
    }
    while (!s.empty())
    {
        ans += s.Top();
        s.pop();
    }
    cout << ans << endl;
}
void inftoprefix(Stack s, string ch, string ans){
    ch = stringrev(ch);
    for (int i = 0; i < ch.length(); i++)
    {
        if (ch[i] == '(')
            ch[i] = ')';
        else if (ch[i] == ')')
            ch[i] = '(';
    }
    int i = 0;
    while (i < ch.length())
    {
        if ((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= '0' && ch[i] <= '9'))
        {
            ans += ch[i];
        }
        else if (ch[i] == '(')
        {
            s.push(ch[i]);
        }
        else if (ch[i] == ')')
        {
            while (!s.empty() && s.Top() != '(')
            {
                ans += s.Top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && priority(ch[i]) < priority(s.Top()))
            {
                ans += s.Top();
                s.pop();
            }
            s.push(ch[i]);
        }
        i++;
    }
    while (!s.empty())
    {
        ans += s.Top();
        s.pop();
    }
    ans = stringrev(ans);
    cout << ans << endl;
}
void posttoinf(Stack1 s, string ch, string ans){
    int i = 0;
    while (i < ch.length())
    {
        if ((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= '0' && ch[i] <= '9'))
        {
            s.push(string(1, ch[i]));
        }
        else
        {
            string t1, t2;
            t1 = s.Top();
            s.pop();
            t2 = s.Top();
            s.pop();
            char h = ch[i];
            ans = '(' + t2 + h + t1 + ')';
            s.push(ans);
        }
        i++;
    }
    if (!s.empty())
    {
        ans = s.Top();
    }
    cout << ans << endl;
}
void pretoinf(Stack1 s, string ch, string ans){
    int i = ch.length() - 1;
    while (i >= 0)
    {
        if ((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= '0' && ch[i] <= '9'))
        {
            s.push(string(1, ch[i]));
        }
        else
        {
            string t1, t2;
            t1 = s.Top();
            s.pop();
            t2 = s.Top();
            s.pop();
            ans = '(' + t1 + ch[i] + t2 + ')';
            s.push(ans);
        }
        i--;
    }
    if (!s.empty())
    {
        ans = s.Top();
    }
    cout << ans << endl;
}
void posttopre(Stack1 s, string ch, string ans){
    int i = 0;
    while (i < ch.length())
    {
        if ((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= '0' && ch[i] <= '9'))
        {
            s.push(string(1, ch[i]));
        }
        else
        {
            string t1, t2;
            t1 = s.Top();
            s.pop();
            t2 = s.Top();
            s.pop();
            ans = ch[i] + t2 + t1;
            s.push(ans);
        }
        i++;
    }
    while (!s.empty())
    {
        ans = s.Top();
        s.pop();
    }
    cout << ans << endl;
}
void pretopost(Stack1 s, string ch, string ans){
    int i = ch.length() - 1;
    while (i >= 0)
    {
        if ((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z') || (ch[i] >= '0' && ch[i] <= '9'))
        {
            s.push(string(1, ch[i]));
        }
        else
        {
            string t1, t2;
            t1 = s.Top();
            s.pop();
            t2 = s.Top();
            s.pop();
            ans = t1 + t2 + ch[i];
            s.push(ans);
        }
        i--;
    }
    while (!s.empty())
    {
        ans = s.Top();
        s.pop();
    }
    cout << ans << endl;
}
int main()
{
    Stack s;
    string ch = "a+b*(c^d-e)";
    string ch1 = "(A+B)*C-D+F";
    string ch2 = "AB-DE+F*/";
    string ch3 = "*+PQ-MN";
    string ch4 = "/-AB*+DEF";
    string ans;
    Stack1 st;
    // inftopost(s,ch,ans);
    // inftoprefix(s,ch,ans);
    // posttoinf(st,ch2,ans);
    // pretoinf(st,ch3,ans);
    // posttopre(st,ch2,ans);
    pretopost(st, ch4, ans);
}
