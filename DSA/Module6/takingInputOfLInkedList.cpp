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
Node *takeInput(){
    int data;cin>>data;
    Node *head= NULL;
    Node *tail = NULL;
    while(data !=-1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;

    }
    return head;
}
int32_t main(){
Node *head = takeInput();
return 0;}