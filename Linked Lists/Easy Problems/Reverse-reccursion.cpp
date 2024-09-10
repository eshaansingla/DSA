#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode*next;
    ListNode(int val){
        this->val=val;
        this->next=nullptr;
    }
};
ListNode*reverse(ListNode*head){
    if(head==nullptr || head->next==nullptr) return head;
    ListNode* newhead=reverse(head->next);
    ListNode*front=head->next;
    front->next=head;
    head->next=nullptr;
    return newhead;
}
int main(){
ListNode*p=new ListNode(1);
p->next=new ListNode(2);
p->next->next=new ListNode(3);
p->next->next->next=new ListNode(4);
p->next->next->next->next=new ListNode(5);
p->next->next->next->next->next=new ListNode(6);
int arr[6];
p=reverse(p);
ListNode*q=p;
while(q){
cout<<q->val<<endl;
q=q->next;
}
}