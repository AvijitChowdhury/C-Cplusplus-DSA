//jay shree krishna
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int val){
        this->val= val;
        this->next = NULL;
    }
};
void insert_at_tail(Node *head,int val){
    Node *temp = head;
    for(;head->next!=NULL;){
        head = head->next;
    }
    if( head->next==NULL){
        head->next = new Node(val);
    }
}
void print_linked_list(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int32_t main(){
    Node *head = new Node(1);
    insert_at_tail(head,10);
    print_linked_list(head);
return 0;}