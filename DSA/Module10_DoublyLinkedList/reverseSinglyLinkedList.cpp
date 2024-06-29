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
void print(Node *head){
    Node *temp  = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }cout<<endl;
}
void reverse(Node *&head, Node *cur){
    if(cur->next==NULL){
        head = cur;
        return;
    }
    reverse(head, cur->next);
    cur->next->next = cur;
    cur->next=NULL;

}
int32_t main(){
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    head->next = a;
    a->next =b;
    
    reverse(head,head);
    print(head);

return 0;}