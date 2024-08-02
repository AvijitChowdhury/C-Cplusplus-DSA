/*
You will be given a binary tree as input in level order. You need to output the sum of all node's values in that tree.

For example:

image

The output for the above tree will be: 210

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
Output Format

Output the total sum of that tree.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

210*/
/*
You will be given a binary tree as input in level order. You need to output the sum of all node's values in that tree.

For example:

image

The output for the above tree will be: 210

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
Output Format

Output the total sum of that tree.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

210*/
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Node {
private:
    

public:
    int val;
    Node *left;
    Node *right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

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

int postorderSum(Node* node, int sum = 0) {
    if (node == NULL) {
        return sum;
    }

    sum = postorderSum(node->left, sum);
    sum = postorderSum(node->right, sum);
    return sum + node->val; 
}

int main() {
    Node* root = inputTree();
    int totalSum = postorderSum(root); 
    cout << totalSum << endl;
    return 0;
}