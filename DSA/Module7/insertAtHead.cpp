//jay shree krishna
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val){
        this->val= val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print_reverse(Node *tail){
    Node *temp = tail;
    while(tail){
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
}
void print_normal(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
void insert_any_position(Node *head, int pos, int val){
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i=1 ;i<=pos-1 ;i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = temp;
}
void insertAtHead(Node *&head,Node *&tail, int val){
    if(head==NULL){
        head = new Node(val);
        tail = head;
        return;
    }
    Node *newNode = new Node(val);
    
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAtTail(Node *&head,Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if(tail==NULL){
        tail = newNode;
        head = newNode;
        return;       
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
int32_t main(){
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = b;
    head->next = a;
    a->prev= head;
    a->next = b;
    b->prev = a;

    print_normal(head);cout<<endl;
    insert_any_position(head,2 , 40);
    print_normal(head);cout<<endl;
    insertAtHead(head,tail,50);
    print_normal(head);cout<<endl;
    insertAtTail(head, tail, 60);
    print_normal(head);
   
    

return 0;}