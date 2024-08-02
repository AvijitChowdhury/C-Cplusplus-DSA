/*
You will be given a binary tree as input in level order. You need to print the binary tree in reverse way. Here, reverse way means you need to print from the last level and from left to right.

For example:

image

The output for the above tree will be: 40 50 60 20 30 10

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
Output Format

Output the tree in reverse way as described.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

40 50 60 20 30 10*/
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

int main() {
    Node* root = inputTree();
    vector<vector<int>> levelOrder = levelOrderTraversal(root);
    reverse(levelOrder.begin(),levelOrder.end());
    for (auto level : levelOrder) {
        for (int value : level) {
            cout << value << " ";
        }
        
    }

    return 0;
}