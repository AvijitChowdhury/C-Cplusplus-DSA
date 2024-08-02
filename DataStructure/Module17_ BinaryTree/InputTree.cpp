
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sum=0;
class Node
{
private:
    /* data */
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void leveOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        sum+=f->val;
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
}
Node* inputTree() {
    int val;
    cin >> val;
    Node* root;
    if (val == -1) {
        root = NULL;
    } else {
        root = new Node(val);
    }

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node* myleft = (l == -1) ? NULL : new Node(l);
        Node* myright = (r == -1) ? NULL : new Node(r);

        temp->left = myleft;
        temp->right = myright;

        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }
    return root;
}
int32_t main()
{
    Node *root = inputTree();

    // preorderTranverse(root);cout<<endl;
    // postorderTranverse(root);cout<<endl;
    // INorderTranverse(root);cout<<endl;
    leveOrder(root);
    cout<<sum<<endl;
}
