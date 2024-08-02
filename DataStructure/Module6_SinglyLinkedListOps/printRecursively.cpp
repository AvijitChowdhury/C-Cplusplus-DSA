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
void printRecursively(Node *temp){
    //base case
    if(temp==NULL){
        
        return;
    }
    printRecursively(temp->next);
    
    cout<<temp->val<<"\t"; 
      
}
int32_t main(){
    Node *head = new Node(1);
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);
    head->next = a;
    a->next = b;
    b->next = c;
    printRecursively(head);

return 0;}