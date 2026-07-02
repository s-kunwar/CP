//Doubly Linked List 
#include <iostream>
using namespace std;


class Node{
public:

int data;
Node*next;
Node*prev;

Node(int data1, Node*next1,Node*prev1){
    data=data1;
    next=next1;
    prev=prev1;
}

void print(){
    Node* temp=this;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

};


Node* arrtoll(int arr[],int len){
    if(len==0) return NULL;

    Node* head=new Node(arr[0],nullptr,nullptr);
    Node* prev=head;
    for(int i=1; i<len; i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}



//Deletion*********************************************************************
Node* deletehead(Node*head){
    if(head==NULL || head->next==nullptr) return NULL;

    Node*newhead=head->next;
    newhead->prev=nullptr;
    head->next=nullptr;

    delete head;
    return newhead;
}

Node* deletetail(Node*head){
    if (head == NULL || head->next == nullptr) return NULL;

    Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    
    Node* newtail=tail->prev;
    newtail->next=nullptr;
    tail->prev=nullptr;

    delete tail;
    return head;
}

Node* deletekth(Node*head,int k){
    int cnt=1;
    Node*temp=head;

    if(temp==NULL) return NULL;
    else if(k==1) return deletehead(head);

    while(temp){
        if(cnt==k){
            if(temp->next==nullptr) return deletetail(head);

            Node*previous=temp->prev;
            Node*front=temp->next;
            previous->next=front;
            front->prev=previous;
            temp->next=nullptr;
            temp->prev=nullptr;
            delete temp;
            return head;
        }
        cnt++;
        temp=temp->next;
    }

    return head;
}

//Insertion*********************************************************

Node*inserthead(Node*head,int val){
    if(head==NULL) return new Node(val,nullptr,nullptr);

    Node*newhead=new Node(val,head,nullptr);
    head->prev=newhead;
    return newhead;
}

Node*inserttail(Node*head,int val){
    if(head==NULL) return new Node(val,nullptr,nullptr);

    Node*tail=head;
    while(tail->next!=nullptr) tail=tail->next;

    Node*newtail=new Node(val,nullptr,tail);
    tail->next=newtail;

    return head;
}

Node* insertkth(Node*head,int k,int val){
    int cnt=1;
    Node*temp=head;

    if(temp==NULL) return new Node(val,nullptr,nullptr);
    else if(k==1) return inserthead(head,val);

    while(temp){
        if(cnt==k){            
            Node* prev=temp->prev;
            Node* newnode=new Node(val,temp,prev);
            prev->next=newnode;
            temp->prev=newnode;

            return head;
        }
        cnt++;
        temp=temp->next;
    }

    return head;
}


//*********************************************

int main(){
    int arr[5]={10,20,30,40,50};
    Node*head=arrtoll(arr,5);

    head = insertkth(head,5,1);
    head->print();


    return 0;
}