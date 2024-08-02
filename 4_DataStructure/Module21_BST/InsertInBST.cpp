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
// Time complexity o(n)
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
// time complexity O(n*h)= O(n^2) in worst case
// in best case O(h) = O(logn)
void insert(Node *&root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return;
    }
    if (root->val >= x && root->left == NULL)
    {
        root->left = new Node(x);
    }
    else if (root->val >= x && root->left != NULL)
    {
        insert(root->left, x);
    }
    else if (root->val < x && root->right == NULL)
    {
        root->right = new Node(x);
    }
    else if (root->val < x && root->right != NULL)
    {
        insert(root->right, x);
    }
}
void traverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    traverse(root->left);
    traverse(root->right);
}
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << temp->val << " ";

        if (temp->left != NULL)
        {
            q.push(temp->left);
        }

        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    Node *root = inputTree();
    int x;
    cin >> x;
    insert(root, 32);
    traverse(root);
    cout << endl;
    levelOrder(root);

    return 0;
}