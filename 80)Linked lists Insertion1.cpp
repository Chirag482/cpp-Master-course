#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;

    //constructor
    node(int d){
        data = d;
        next = NULL;
    }
};

//functions (Procedural Programming)
void build(){

}

//passing a pointer by refrence
void insertAtHead(node*&head,int d){
    if(head == NULL){
        head = new node(d);  //here we use dynamically allocation becuz if we use static allocation here than after the exceution of the function the linked will be deleted
        return;
    }
    node *n = new node(d);
    n->next = head;
    head = n;
}
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<" ,";
        head = head->next;
    }
}
int length(node*head){
    int cnt = 0;
    while(head!=NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

void insertAtTail(node*&head,int d){
    if(head==NULL){
        head = new node(d);
        return ;
    }
    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(d);
    return ;
}

void insertAtMiddle(node*&head,int d,int p){
    //corner case
    if(head == NULL or p==0){
        insertAtHead(head,d);
        return ;
    }
    else if(p>length(head)){
        insertAtTail(head,d);
    }
    //middle case
    else{
        //take p-1 jumps to reach the desired position
        int jump = 1;
        node*temp = head;
        while(jump<=p-1){
            temp = temp->next;
            jump++;
        }
        //create a new node
        node*n = new node(d);
        n->next = temp->next;
        temp->next = n;
    }
}

int main()
{
    node*head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);

    insertAtMiddle(head,4,3);
    insertAtTail(head,7);
    print(head);

    return 0;
}
