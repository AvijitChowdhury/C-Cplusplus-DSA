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

int32_t main(){
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = b;
    head->next = a;
    a->prev= head;
    a->next = b;
    b->prev = a;

    print_normal(head);
    cout<<endl;
    print_reverse(tail);
    

return 0;}