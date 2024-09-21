#include<iostream>
#include<string>
using namespace std;
class Stack{
    public: 
    char arr[100];
    int top;
    int size;
    int tsize;
    Stack(){
        top=-1;
        size=0;
        tsize=100;
    }
    void push(char x){
        if(top>=tsize-1){
            cout<<"Overflow"<<endl;
        }
        else{
            arr[++top]=x;
            size++;
        }
    }
    void pop(){
        if(top<=-1){
            cout<<"Underflow"<<endl;
        }
        else{
            top--;
            size--;
        }
    }
    int empty(){
        if(size<=0) return 1;
        else return 0; 
    }
    char Top(){
        return arr[top];
    }
};
int priority(char s){
if(s=='^') return 3;
else if(s=='*' || s=='/') return 2;
else return 1;
}
int main(){
    Stack s;
    string ch="a+b*(c^d-e)";
    string ans;
    int i=0;
    while(i<ch.length()){
        if((ch[i]>='A' && ch[i]<='Z')||(ch[i]>='a' && ch[i]<='z')||(ch[i]>='0' && ch[i]<='9')){ 
            ans=ans+ch[i];
        }
        else if(ch[i]=='('){
            s.push(ch[i]);
        }
        else if(ch[i]==')'){
            while(!s.empty() && s.Top()!='('){
                ans=ans+s.Top();
                s.pop();
            }
            s.pop();
        }
        else{
        while(!s.empty() && (priority(ch[i])<priority(s.Top()))){
            ans=ans+s.Top();
            s.pop();
        }
        s.push(ch[i]);
        }
        i++;
    }
     while (!s.empty()) {
        ans += s.Top();
        s.pop();
    }
    cout<<ans;
}