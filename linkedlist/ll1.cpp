#include<iostream>

/*
Implementing a linked list 
(Linked list consists of nodes which each have 
data and the memory location of the next node
unlike arrays, these nodes do not have any contigous memory locations, that's
why we keep the memory loc of the next node)

you can create nodes using either classes(better suited) or structs
*/

using namespace std;

struct Node
{
    public:
    int data;  //contains data for the current node
    Node* next; // this pointer 'next' points to the next node

    Node(int val,auto ptr){
        data=val;
        next=ptr;
    }

};

Node* arrtoll(int arr[],int len){
    if(len==0) return NULL;

    Node* head =new Node(arr[0],nullptr);
    Node* mover=head;
    for(int x=1; x<=len; x++){
        Node* temp=new Node(arr[x],nullptr);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int main(){

    int arr[5]={10,20,30,40,50};
    Node* Arr= arrtoll(arr,5); //Gets you the head of the linked list

    cout<<Arr<<'\n'<<Arr->data<<'\n';

    //Traversing a linked list (never interefere with the original head)
    Node* temp=Arr;
    while(temp){
        cout<<temp->data<<' ';
        temp=temp->next;
    }

    return 0;
}