/*
You have been given a binary tree of integers. You are supposed to find the left view of the binary tree. The left view of a binary tree is the set of all nodes that are visible when the binary tree is viewed from the left side.

Example:

The left view of the above binary tree is  {5, 7, 14, 25}.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
0 <= N <= 3000
1 <= data <= 10^5 and data!=-1

Where ‘T’ is the number of test cases, and ‘N’ is the total number of nodes in the binary tree, and “data” is the value of the binary tree node

Time Limit: 1 sec
Sample Input 1:
2
3 4 -1 -1 -1 
2 8 7 -1 5 -1 -1 1 -1 -1 -1
Sample Output 1:
3 4
2 8 5 1
Explanation of Sample Input 1:
For the first test case, node 3 and node 4 are visible when the binary tree is viewed from the left.

For the second test case, nodes 2, 8, 5, 1 are visible when the binary tree is viewed from the left.
Sample Input 2:
2
1 3 5 12 -1 8 -1 -1 -1 -1 -1 
9 6 3 -1 -1 4 8 -1 -1 -1 -1 
Sample Output 2:
1 3 12
9 6 4
Explanation of Sample Input 2:
For the first test case, nodes 1, 3, 12 are visible when the binary tree is viewed from the left.

For the second test case, nodes 9, 6, 4 are visible when the binary tree is viewed from the left.*/
// void f(TreeNode<int>*root,vector<int>&p,int lvl)

// {

//     if(!root)return;

//     if(lvl ==p.size())p.push_back(root->data);

//     f(root->left,p,lvl+1);

//     f(root->right,p,lvl+1);

// }

// vector<int> getLeftView(TreeNode<int> *root)

// {

//     //    Write your code here

//     vector<int>p;

//     if(!root)return p;

//     f(root,p,0);

//     return p;

// }

//second solution 
vector<int> leftVi(TreeNode<int> *root,vector<int>v,int level){
    queue<TreeNode<int>*> q;
    if(!root){return v;}
    q.push(root);
    while (!q.empty()) {
      int level_size = q.size();
      // Add the first node of each level to the result
      v.push_back(q.front()->data);
      for (int i = 0; i < level_size; ++i) {
        TreeNode<int>* node = q.front();
        q.pop();
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
    }
  }
    return v;
    // if(root==NULL){return;}
    // if(level==v.size())v.push_back(root->data);
    // leftVi(root->left,v,level+1);
    // leftVi(root->right,v,level+1);
    
    
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> v;
    return leftVi(root, v,0);

    
}