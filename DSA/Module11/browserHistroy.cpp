// jay shree krishna
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string str;
    Node *next;
    Node *prev;

    Node(string str)
    {
        this->str = str;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_at_tail(Node *&head, Node *&tail, string str)
{
    Node *newNode = new Node(str);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int32_t main()
{
    Node *head = NULL;
    Node *tail = NULL;
    string str;
    while (true)
    {
        cin >> str;
        if (str == "end")
            break;
        insert_at_tail(head, tail, str);
    }
    int q;
    string address;
    string browser;
    cin >> q;

    cin.ignore();
    Node *temp = head;
    Node *cur = head;
    
    q+=5;
    
    while (q--)
    {
         cin >> address;
         cin.ignore();
        if (address == "visit")
        {
            cin >> browser;
            cin.ignore();
            temp = head;
            while (temp->next != NULL)
            {
                if (temp->str == browser)
                {
                    cout << browser << endl;
                    break;
                }
                cur = cur->next;
                temp = temp->next;
                if (temp->next == NULL && temp->str == browser)
                {
                    cout << browser << endl;
                }
                else if (temp->next == NULL && temp->str != browser)
                {
                    cout << "Not Avalilable" << endl;
                }
            }
        }
        else if (address == "prev")
        {
            if (cur->prev != NULL)
            {
                cur = cur->prev;
                cout << cur->str << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else
        {
            if (cur->next != NULL)
            {
                cur = cur->next;
                cout << cur->str << endl;
            }
            else 
            {
                cout << "Not Available" << endl;
            }
        }
    }
}