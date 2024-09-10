#include<iostream>
using namespace std;
class NodeList{
public:
int data;
NodeList*next;
NodeList(int data){
    this->data=data;
    this->next=nullptr;
}
NodeList(int data,NodeList*next){
    this->data=data;
    this->next=next;
}
/*
void store(NodeList*head,int*arr){
    NodeList*temp=head;
    int i=0;
    while(temp){
        arr[i]=temp->data;
        temp=temp->next;
        i++;
    }
}
NodeList* change(NodeList*head,int*arr){
    NodeList*temp=head;
    int i=5;
    while(temp && i>=0){
        temp->data=arr[i];
        i--;
        temp=temp->next;
    }
    return temp;
}
*/
NodeList* reverse(NodeList*head){
NodeList*prev=nullptr;
NodeList*temp=head;
NodeList*front;
while(temp){
front=temp->next;
temp->next=prev;
prev=temp;
temp=front;
}
return prev;
}
};
int main(){
NodeList*p=new NodeList(1);
p->next=new NodeList(2);
p->next->next=new NodeList(3);
p->next->next->next=new NodeList(4);
p->next->next->next->next=new NodeList(5);
p->next->next->next->next->next=new NodeList(6);
int arr[6];
p=p->reverse(p);
NodeList*q=p;
while(q){
cout<<q->data<<endl;
q=q->next;
}
}