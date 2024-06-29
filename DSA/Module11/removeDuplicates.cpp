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
void removeDuplicates( Node* start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;

        while (ptr2->next != NULL) {
            if (ptr1->val == ptr2->next->val) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else 
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
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
void sort(Node *head){
    for(Node *i = head;i->next!=NULL;i=i->next){
        for(Node *j = i->next;j!=NULL; j=j->next){
            if(i->val>j->val){
                swap(i->val,j->val);
            }
        }
    }
}
void printList(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }cout<<endl;
}
int32_t main(){
    Node *head = takeInput();
    removeDuplicates(head);
    sort(head);
    printList(head);


return 0;}