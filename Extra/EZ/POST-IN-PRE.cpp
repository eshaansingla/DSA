#include<bits/stdc++.h>
using namespace std;
int priority(char s){
if (s == '^') return 3;
else if (s == '*' || s == '/') return 2;
else if (s == '+' || s == '-') return 1;
return 0;
}
string reverse(string rev){
for(int i=0;i<rev.length()/2;i++){
    char temp=rev[i];
    rev[i]=rev[rev.length()-1-i];
    rev[rev.length()-1-i]=temp;
    }
return rev;
}
void inftopost(string s){
stack<char>st;
string ans;
int i=0;
int n=s.length();
while(i<n){
    if((s[i]>='0' and s[i]<='9') || (s[i]>='a' and s[i]<='z') || (s[i]>='A' and s[i]<='Z')) ans+=s[i];
    else if(s[i]=='(') st.push(s[i]);
    else if(s[i]==')'){
        while(!st.empty() && st.top()!='('){
        ans+=st.top();
        st.pop();
    }
    st.pop();
    }
    else{
        while(!st.empty() && (priority(st.top())>=priority(s[i]))){
            ans+=st.top();
            st.pop();
        }
        st.push(s[i]);
    }
i++;
}
while(!st.empty()){
    ans+=st.top();
    st.pop();
}
cout<<ans<<endl;
}
void inftopre(string s){
    s=reverse(s);
    stack<char>st;
    string ans;
    int n=s.length();
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    int i=0;
    while(i<n){
        if((s[i]>='0' and s[i]<='9') || (s[i]>='a' and s[i]<='z') || (s[i]>='A' and s[i]<='Z')) ans+=s[i];
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(st.top()!='(' && !st.empty()){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && priority(st.top())>priority(s[i])){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    ans=reverse(ans);
    cout<<ans<<endl;
}
void posttoinf(string s){
    int i=0;
    int n=s.length();
    string exp;
    string ans;
    stack<string>st;
    while(i<n){
        if((s[i]>='0' and s[i]<='9') || (s[i]>='a' and s[i]<='z') || (s[i]>='A' and s[i]<='Z')) st.push(string(1, s[i]));
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            exp='('+t2+s[i]+t1+')';
            st.push(exp);
        }
        i++;
    }
    ans+=st.top();
    cout<<ans<<endl;
}
void pretoinf(string s){
    string ans;
    stack<string>st;
    int i=s.length()-1;
    while(i>=0){
       if((s[i]>='0' and s[i]<='9') || (s[i]>='a' and s[i]<='z') || (s[i]>='A' and s[i]<='Z')) st.push(string(1, s[i]));
       else{
        string t1=st.top();
        st.pop();
        string t2=st.top();
        st.pop();
        st.push('('+t1+s[i]+t2+')');
       }
       i--;
    }
    ans+=st.top();
    cout<<ans<<endl;
}
void pretopost(string s){
    int i=s.length()-1;
    stack<string>st;
    while(i>=0){
        if((s[i]>='0' and s[i]<='9') || (s[i]>='a' and s[i]<='z') || (s[i]>='A' and s[i]<='Z')) st.push(string(1, s[i]));
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            st.push(t1+t2+s[i]);
        }
       i--;
    }
    cout<<st.top()<<endl;
}
void posttopre(string s){
    int i=0;
    stack<string>st;
    while(i<s.length()){
        if((s[i]>='0' and s[i]<='9') || (s[i]>='a' and s[i]<='z') || (s[i]>='A' and s[i]<='Z')) st.push(string(1, s[i]));
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            st.push(s[i]+t2+t1);
        }
        i++;
    }
    cout<<st.top()<<endl;
}
int main(){
string expression = "a+b*(c^d-e)";
inftopost(expression);
inftopre(expression);
posttoinf("abcd^e-*+");
pretoinf("+a*b-^cde");
pretopost("+a*b-^cde");
posttopre("abcd^e-*+");
}