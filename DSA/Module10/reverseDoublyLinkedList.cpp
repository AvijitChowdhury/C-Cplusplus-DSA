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
void print(Node *head){
    Node *temp  = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }cout<<endl;
}
void reverse(Node *&head, Node *&tail){
    Node *i = head;
    Node *j = tail;
    while(i!= j && i->next!=j){
        swap(i->val, j->val);
        i= i->next;
        j = j->prev;
    }
    swap(i->val,j->val);
    

}
int32_t main(){
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    head->next = a;
    a->next =b;
    a->prev=head;
    b->prev = a;
    Node *tail = b;
    
    reverse(head,tail);
    print(head);

return 0;}