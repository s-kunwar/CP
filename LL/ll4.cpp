#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int dat,Node* nxt,Node*prv){
        data=dat;
        next=nxt;
        prev=prv;
    }

    void print(){
        Node*temp=this;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

Node* arrtoll(int arr[],int len){
    Node* head=new Node(arr[0],nullptr,nullptr);
    Node* prev=head;

    for(int i=1; i<len; i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}


Node* reversell(Node*head){
    if(head==NULL || head->next==NULL) return head;
    
    Node*store;
    while(head->next){
        store=head->next;
        head->next=head->prev;
        head->prev=store;

        head=store;   
    }
    head->next=head->prev;
    head->prev=nullptr;
    return head;
}


int main(){

    int arr[5]={10,20,30,40,50};
    Node* head=arrtoll(arr,5);
    head=reversell(head);
    head->print();

    return 0;
}