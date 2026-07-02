#include <iostream>
using namespace std;

struct Node
{
public:
    int data;  
    Node *next;

    Node(int val, auto ptr)
    {
        data = val;
        next = ptr;
    }
};

Node* arrtoll(int arr[],int len)
{
    if(len==0) return NULL;

    Node *head = new Node(arr[0], nullptr);
    Node *mover = head;
    for (int x = 1; x <= len; x++)
    {
        Node *temp = new Node(arr[x], nullptr);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    Node* temp=head;
    cout<<endl;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


//Deletion*********************************************************************************

Node* removehead(Node* head){
    if(head==NULL) return head; //empty list
    Node* temp=head;
    head=head->next;
    free(temp);

    return head;
}

Node* removetail(Node* head){

    if(head==NULL) return head; //empty list
    else if(head->next==nullptr) return NULL; //one element only
    //else
    Node* temp=head;
    //get the last second element
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;

    return head;
}


Node* removekth(Node* head,int k){
    if(head==NULL) return head;
    else if(k==1) return removehead(head);
    //else
    int cnt=1;
    Node* temp=head;
    while(temp->next!=nullptr){
        if(cnt+1==k){
            Node* toremove=temp->next;
            temp->next=toremove->next;
            free(toremove);
            return head;
        }
        cnt++;
        temp=temp->next;
    }

    return head;
}


Node* removevalue(Node* head,int val){
    if(head==NULL) return head;
    else if(head->data==val) return removehead(head);
    //else
    Node* temp=head;
    while(temp->next!=nullptr){
        if(temp->next->data==val){
            Node* toremove=temp->next;
            temp->next=toremove->next;
            free(toremove);
            return head;
        }
        temp=temp->next;
    }

    return head;
}



//Incertion********************************************************************************

Node* inserthead(Node* head,int val){
    Node* insert=new Node(val,head);
    head=insert;
    return head;
}
Node* inserttail(Node* head,int val){
    Node* insert=new Node(val,nullptr);
    if(head==NULL) return insert;
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=insert;
    return head;
}

Node* insertkth(Node* head,int k, int val){
    if(head==NULL){
        if(k==1) return inserthead(head,val);
        else return NULL;
    }
    else if(k==1) return inserthead(head,val);
    int cnt=1;
    Node* temp=head;
    while(temp){
        if(cnt+1==k){
            Node* toinsert=new Node(val,temp->next);
            temp->next=toinsert;
            return head;
        }
        cnt++;
        temp=temp->next;
    }

    return head;
}

Node* insertatval(Node* head,int atval, int val){
    if(head==NULL){
        if(head->data==atval) return inserthead(head,val);
        else return NULL;
    }
    else if(head->data==atval) return inserthead(head,val);

    Node* temp=head;
    while(temp){
        if(temp->next->data==atval){
            Node* toinsert=new Node(val,temp->next);
            temp->next=toinsert;
            return head;
        }
        temp=temp->next;
    }

    return head;
}




int main(){

    int arr[5]={10,20,30,40,50};
    Node* head=arrtoll(arr,5);
    head=insertatval(head,50,100);
    print(head);

    return 0;
}