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
void print_normal(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int32_t main(){
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while(true){
        cin>>val;
        if(val==-1)break;
        insertAtTail(head,tail,val);
    }
print_normal(head);

   
    

return 0;}