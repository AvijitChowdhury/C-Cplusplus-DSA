// jay shree krishna
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void print_reverse(Node *tail)
{
    Node *temp = tail;
    while (tail)
    {
        cout << tail->val << " ";
        tail = tail->prev;
    }
}
void print_normal(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int size(Node *&head)
{
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void insertAtHead(Node *&head, Node *&tail, int &val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insert_tail(Node *&head, Node *&tail, int &val)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}
void insert_any_position(Node *&head, Node *&tail, int &pos, int &val)
{

    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        if(temp){
        temp = temp->next;
    }}
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = temp;
    
   
}
void push_at(Node *&head,Node *&tail, int position,int newElement) {
    position+=1;
      Node* newNode = new Node(newElement); 
    
      newNode->next = NULL;
      newNode->prev = NULL;
     if (position == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
      } else {
        Node* temp = head;
        for(int i =1 ; i < position-1; i++) {
          if(temp != NULL) {
            temp = temp->next;
          }
        }
        if(temp != NULL) {
          newNode->next = temp->next;
          newNode->prev = temp;
          temp->next = newNode;
          if(newNode->next != NULL)
            newNode->next->prev = newNode;  
        }  
      }
    }
int32_t main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val=0;
    int t = 1;
    cin >> t;
    int pos = 0;
    int data;
    while (t--)
    {

        cin >> pos >> val;
        //cout << pos << " " << data << " " << size(head) << endl;
        
        if (pos > size(head))
        {
            cout << "Invalid" << endl;
        }
        else if (pos == 0)
        {
            insertAtHead(head, tail, val);
            cout << "L -> ";
            print_normal(head);
            cout << endl
                 << "R -> ";
            print_reverse(tail);
            cout << endl;
            
        }
       
        else if (pos < size(head))
        {
            push_at(head, tail, pos, val);
            cout << "L -> ";
            print_normal(head);
            cout << endl
                 << "R -> ";
            print_reverse(tail);
            cout << endl;
        }
        else if (pos == size(head))
        {
            Node *newNode = new Node(val);
            
            insert_tail(head, tail, val);
            cout << "L -> ";
            print_normal(head);
            cout << endl
                 << "R -> ";
            print_reverse(tail);
            cout << endl;
           
        }
        
    }
    return 0;
}