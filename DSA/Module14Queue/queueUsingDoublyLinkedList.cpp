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
class myQueue{
    public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz =0;
    void push(int val){
        sz++;
        Node *newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }
    void pop(){
        sz--;
        Node *deleteNode = head;
        if(head == NULL){
            tail = NULL;
            delete deleteNode;           
            return;
        }
        
        head= head->next;       
        head->prev = NULL;
        delete deleteNode;

    }
    int front(){
        return head->val;
    }
    int size(){
        return sz;
    }
    bool empty(){
        if(sz==0)return true;
        else false;
    }
};
int32_t main(){
    myQueue q;
    // q.push(20);
    // cout<<q.front()<<endl;
    // q.push(30);
    // q.pop();
    // cout<<q.size()<<endl;
    // q.push(50);
    // cout<<q.front()<<endl;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }
return 0;}