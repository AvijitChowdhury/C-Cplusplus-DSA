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
    list<int>l;
  
    void push(int val){
        l.push_back(val);
    }
    void pop(){
        
        l.pop_front();
    }
    int front(){
        return l.front();
    }
    int size(){
        return l.size();
    }
    bool empty(){
        return l.empty();
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