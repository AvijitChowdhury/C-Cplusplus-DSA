/*
You will be given a binary tree as input in level order. You need to give the maximum and minimum values of all the leaf nodes available.

For example:

image

The output for the above tree will be: 60 40

Input Format

Input will contain the binary tree in level order. -1 means there is no node available.
Constraints

1 <= Maximum number of nodes <= 10^5
1 <= Node's value <= 1000
Output Format

Output the maximum value then the minimum value of all leaf nodes.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

60 40*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node
{
private:
    /* data */
public:
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val= val;
        this->left=NULL;
        this->right=NULL;
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

int x=1,y=1000;
void getLeafCount(Node* node) 
{ 
    if(node == NULL)     
        return; 
    if(node->left == NULL && node->right == NULL){ 
        x= max(x,node->val);
        y = min(y,node->val);}         
    getLeafCount(node->left);
    getLeafCount(node->right); 
} 

int32_t main(){
    Node *root = inputTree();
    getLeafCount(root);
    cout<<x<<" "<<y<<endl;
    
}