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
void sort(Node *head){
    for(Node *i = head;i->next!=NULL;i=i->next){
        for(Node *j = i->next;j!=NULL; j=j->next){
            if(i->val>j->val){
                swap(i->val,j->val);
            }
        }
    }
}
void printRecursively(Node *temp){
    //base case
    if(temp==NULL){
        
        return;
    }
    cout<<temp->val<<"\t"; 
    printRecursively(temp->next);
    
    
      
}
int32_t main(){Node *head = new Node(1);
    Node *a = new Node(4);
    Node *b = new Node(2);
    Node *c = new Node(3);
    head->next = a;
    a->next = b;
    b->next = c;
    sort(head);
    printRecursively(head);


return 0;}