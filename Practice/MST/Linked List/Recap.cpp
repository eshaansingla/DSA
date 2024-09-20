#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node*next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
     Node(int data,Node*next){
        this->data=data;
        this->next=next;
    }
    void print(Node*head){
        Node*temp=head;
        while(temp){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    string search(int k,Node*head){
        Node*temp=head;
        while(temp){
            if(temp->data==k){
                 return "Found :)";
            }
            temp=temp->next;
        }
        return "Not Found :(";
    }
    Node* del(Node*head,int k){
         Node*temp=head;
         Node*prev=nullptr;
        if(k==head->data) return new Node(head->next->data,head->next->next);
        while(temp){
            if(temp->data==k){
                prev->next=temp->next;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
    Node* insert(Node*head,int k,int l){
        Node*temp=head;
        if(temp->data==k){
        return new Node(l,head);
        }
        while(temp){
            if(temp->data==k){
                temp->next=new Node(l,temp->next);
                break;
            }
            temp=temp->next;
        }
        return head;
    }
    void middle(Node*head){
        Node*slow=head;
        Node*fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        cout<<"Middle is: "<<slow->data<<endl;
    }
    Node* reverse(Node*head){
        Node*prev=nullptr;
        Node*temp=head;
        Node*front=nullptr;
        while(temp){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    void detectloop(Node*head){
        int l=1;
        Node*slow=head;
        Node*fast=head;
        bool t=0;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                slow=head;
                t=1;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                cout<<"LOOP and data is: "<<fast->data<<endl;
                break;
        }
        }
        fast=fast->next;
    while(fast!=slow){
        fast=fast->next;
        l++;
    }
    cout<<"Length: "<<l;
    if(t==0) cout<<"No loop"<<endl<<"Length: "<<0;
    delete slow;
    delete fast;
}
    void pali(Node*head){
        Node*slow=head;
        Node*fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        bool pal=1;
        Node*first=head;
        Node*second=slow->next;
        while(second){
            if(first->data!=second->data){
                pal=0;
                break;
            }
            first=first->next;
            second=second->next;
        }
       slow->next=reverse(slow->next);
       if(pal==1) cout<<"Pali"<<endl;
       else cout<<"Not Pali"<<endl;
    }
    Node* evenodd(Node*head){
        if(head==nullptr) return head;
        Node*odd=head;
        Node*even=odd->next;
        Node*even1=even;
        while(even && even->next){
            odd->next=odd->next->next;
            even->next=even->next->next;
            odd=odd->next;
            even=even->next;
        }
        odd->next=even1;
        return head;
    }
    
};
int main(){
Node*p=new Node(5);
p->next=new Node(2);
p->next->next=new Node(3);
p->next->next->next=new Node(4);
p->next->next->next->next=new Node(1);
p->next->next->next->next->next=new Node(9);
p->next->next->next->next->next->next=new Node(10);
p->next->next->next->next->next->next->next=new Node(12);
p->next->next->next->next->next->next->next->next=new Node(15);
//p->next->next->next->next->next->next->next->next->next=new Node(56,p->next->next->next->next);
/*p->print(p);
cout<<endl;
cout<<p->search(6,p)<<endl;
cout<<p->search(9,p)<<endl;
p=p->del(p,5);
p->print(p);
cout<<endl;
p=p->insert(p,9,4);
p->print(p);
p->middle(p);
Node*q=q->reverse(p);
q->print(q);
q->middle(q);
p->detectloop(p);*/
Node*pal=new Node(1);
pal->next=new Node(2);
pal->next->next=new Node(3);
//pal->next->next->next=new Node(3);
//pal->next->next->next->next=new Node(2);
//pal->next->next->next->next->next=new Node(1);
pal->next->next->next=new Node(2);
pal->next->next->next->next=new Node(1);
//pal->print(pal);
//pal->pali(pal);
//pal->print(pal);
//pal=pal->evenodd(pal);
//pal->print(pal);
Node*oe=oe->evenodd(p);
oe->print(oe);
}