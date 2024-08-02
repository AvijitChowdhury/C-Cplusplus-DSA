#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *inputTree()
{
    int val;
    cin >> val;
    if (val == -1)
    {
        return nullptr;
    }

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cin >> val; // Read left child value
        if (val != -1)
        {
            temp->left = new Node(val);
            q.push(temp->left);
        }

        cin >> val; // Read right child value
        if (val != -1)
        {
            temp->right = new Node(val);
            q.push(temp->right);
        }
    }

    return root;
}
//Time complexity o(n)
bool search(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->val == x)
    {
        return true;
    }
    if (root->val <= x)
    {
        return search(root->left, x);
    }
    else
    {
        return search(root->right, x);
    }
}

int main()
{
    Node *root = inputTree();
    if (search(root, 6))
    {
        cout << "Found";
    }
    else
    {
        cout << "Not Found";
    }

    return 0;
}