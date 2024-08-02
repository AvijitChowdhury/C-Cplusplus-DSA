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
class Queue{
    public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int val){
        sz++;
        Node *newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }tail->next = newNode;
        tail = tail->next;
    }
    void pop(){
        sz--;
        Node *deleteNode = head;
        head= head->next;
        delete deleteNode;
    if(head == NULL){
        tail = NULL;
    }
    }
    int siz(){
        return sz;
    }
    int front(){
        return head->val;
    }
    bool empty(){
        if(sz==0)return true;
        else return false;
    }
};
int32_t main(){
    Queue q;
    q.push(20);
    cout<<q.front()<<endl;
    q.push(30);
    q.pop();
    cout<<q.siz()<<endl;
    q.push(50);
    cout<<q.front()<<endl;

return 0;}