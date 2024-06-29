/*
You will be given a binary tree as input in level order. Also you will be given a level . You need to print all the node's values in that level from left to right. Assume that level starts from .

For example:

image

If , then the output for the above tree will be: 40 50 60

Note: If the level  is not a valid level, the print "Invalid".

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output all the node's values in level .
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
0
Sample Output 0

10
Sample Input 1

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
1
Sample Output 1

20 30
Sample Input 2

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
2
Sample Output 2

40 50 60
Sample Input 3

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
3
Sample Output 3

Invalid*/
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
    int x;
    cin>>x;
    vector<vector<int>> levelOrder = levelOrderTraversal(root);
    
    if(x>=levelOrder.size()){
        cout<<"Invalid";
    }else{
    for(int i=0;i<levelOrder[x].size();i++){
        cout<<levelOrder[x][i]<<" ";
    }}
    

    return 0;
}