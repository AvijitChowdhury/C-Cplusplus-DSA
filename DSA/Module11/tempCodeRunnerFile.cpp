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
int size(Node *head){
    Node *temp = head;
    int cnt=0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void insert_tail(Node *head,Node *tail, int val){
    Node *newNode = new Node(val);
    if(tail==NULL){head = newNode;tail = newNode;return;}
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}
int32_t main(){
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    int t=1;
    cin>>t;
    while(t--){
        int pos,val;
        cin>>pos>>val;
        if(pos>=size(head)){cout<<"Invalid"<<endl;}
        else{
            insert_any_position(head,pos,val);
            cout<<"L -> ";
            print_normal(head);cout<<endl<<"R -> ";
            print_reverse(head);
        }
            
        }
        
    }
   
    

return 0;}