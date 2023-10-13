// jay shree krishna
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_anyPos(Node *head, int val, int newVal)
{
    Node *temp = head;
    Node *newNode = new Node(newVal);
    while (temp->next != NULL)
    {
        if (temp->val == val)
        {
            Node *temp1 = temp->next;
            temp->next = newNode;
            newNode->next = temp1;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (temp->next == NULL)
    {
        temp->next = newNode;
    }
}
void insert_at_head(Node *&head,int val){//reference nite hobe karon head ke update kortesi
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
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
int32_t main()
{
    Node *head = new Node(1);
    Node *a = new Node(2);
    Node *b = new Node(3);
    Node *c = new Node(4);
    head->next = a;
    a->next = b;
    b->next = c;
    print_Linked_list(head);
    insert_at_anyPos(head, 3, 5);
    print_Linked_list(head);
    insert_at_head(head,10);
    print_Linked_list(head);
    return 0;
}