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
void delete_head(Node *&head){
    Node *temp = head;
    head = temp->next;
    delete temp;
}

void print_Linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int32_t main(){
     Node *head = new Node(1);
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);
    head->next = a;
    a->next = b;
    b->next = c; 
    print_Linked_list(head);
    
    delete_head(head);
    print_Linked_list(head);

return 0;}