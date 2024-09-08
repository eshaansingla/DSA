#include<iostream>
using namespace std;
int arr[100];
int Top=-1;
int n=100;
class Stack{
    public:    
    void push(int x){
        if(Top<n-1) arr[++Top]=x;
        else cout<<"Overflow"<<endl;
    }
    int top(){
        return arr[Top];
    }
    void pop(){
        Top--;
    }
    int size(){
        return Top+1;
    }
};
int main(){
Stack st;
st.push(69);
st.push(1);
st.push(29);
st.push(7);
cout<<st.top()<<endl;
st.pop();
cout<<st.top()<<endl;
cout<<st.size();
}