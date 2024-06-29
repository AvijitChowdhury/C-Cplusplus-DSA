/*
You will be given a binary tree as input in level order. You need to tell if the binary tree is perfect or not. A binary tree is called perfect if all leaf nodes are at the maximum depth of the tree, and the tree is completely filled with no gaps.

Here is an example of perfect binary tree:

image

Also there is formula available to tell if a binary tree is perfect or not. The formula is :

Total number of nodes = -1
Note: Here depth is counted from . In the above image maximum depth is , so total number of nodes are . So there should be  nodes to call it a perfect binary tree.

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output  if the tree is perfect,  otherwise.
Sample Input 0

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 0

YES
Sample Input 1

10 20 30 40 -1 60 -1 -1 -1 -1 -1
Sample Output 1

NO
Sample Input 2

10 20 -1 -1 -1
Sample Output 2

NO
Sample Input 3

10 20 30 40 50 60 70 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 3

YES*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* inputTree() {
    int val;
    cin >> val;
    if (val == -1) {
        return nullptr;
    }

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cin >> val;  // Read left child value
        if (val != -1) {
            temp->left = new Node(val);
            q.push(temp->left);
        }

        cin >> val;  // Read right child value
        if (val != -1) {
            temp->right = new Node(val);
            q.push(temp->right);
        }
    }

    return root;
}

vector<vector<int>> levelOrderTraversal(Node* root) {
    vector<vector<int>> levels;
    if (!root) {
        return levels; 
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        vector<int> currentLevel;
        int levelSize = q.size();

        for (int i = 0; i < levelSize; ++i) {
            Node* temp = q.front();
            q.pop();

            currentLevel.push_back(temp->val);

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }

        levels.push_back(currentLevel);
    }

    return levels;
}
int countNode(Node *root){
    if(root==NULL){return 0;}
    int l= countNode(root->left);
    int r= countNode(root->right);
    return l+r+1;
}
int maxDepth(Node* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
long long power(long long A, long long B)
{
    if (B == 0)
        return 1;

    long long res = power(A, B / 2);

    if (B % 2)
        return res * res * A;
    else
        return res * res;
}
int main() {
    Node* root = inputTree();
    long long cnt = (long long)countNode(root);
    long long  ht= (long long)maxDepth(root);
    if(cnt==2){cout<<"NO"<<endl;}
    
    else if(power(2,ht)-1==cnt){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    
    

    return 0;
}