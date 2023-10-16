/*
Problem Statement

You have a singly linked list which is empty initially. Then you will be given Q queries. In each query you will be given two values X and V.

If X is 0 that means you will insert the value V to the head of the linked list.
And if X is 1 then you will insert the value V to the tail of the linked list.
After that for each query you need to print the value of the head and tail of the list.
Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 10^6;
0 <= X <= 1;
0 <= V <= 10^9
Output Format

For each query ouput the value of head and tail of the linked list.
Sample Input 0

5
0 10
0 20
1 30
0 40
1 50
Sample Output 0

10 10
20 10
20 30
40 30
40 50*/
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
Node *head = NULL;
Node *tail = NULL;

void solve1(int val)
{
    if (head == NULL)
    {
        head = new Node(val);
        tail = head;
    }
    
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    cout << val << " " << tail->val << endl;
}
void solve2(int val)
{
    Node *temp = head;
    if (temp == NULL)
    {
        temp = new Node(val);
        head = temp;
        tail = head;
    }

    tail->next = new Node(val);
    tail = tail->next;
    cout << head->val << " " << val << endl;
}
int main()
{
  

    int t;
    cin >> t;

    while (t--)
    {
        int x, y;
        cin >> x >> y;

        // solve(x,y);
        if (x == 0)
        {
            solve1(y);
        }
        else
        {
            solve2(y);
        }
    }

    return 0;
}