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
int32_t main(){
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = a;
     Node *slow = head;
     Node *fast = head;
     int flag = 0;
    
     while(fast !=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast==slow){
            flag =1 ;
            //cout<<"Cycle Detected"<<endl;
            break;
        }
     }
     if(flag){
        cout<<"Cycle Detected"<<endl;
     }else{
        cout<<"No Cycle"<<endl;
     }


return 0;}