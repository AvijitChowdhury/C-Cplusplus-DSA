/*
Ninja has been given a binary tree having N nodes and an integer M, he needs to find the level of node M. He finds it difficult to solve and asks for your help.

Note:

Consider root to be at level 1. It is guaranteed that all the nodes in the binary tree have distinct values.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 5
0 <= N <= 3000
0 <= node data <= 10^9  

Time Limit: 1 sec
Sample Input 1:
2
1 2 3 -1 -1 -1  6 -1 -1
6
1 2 -1 -1 -1
1
Sample Output 1:
3
1
Explanation of Sample Input 1:
 For the first test case, the given binary tree is shown below.
 Here, we see that node 6 is at a distance of 2 units from the root(node 1). Hence, our level will be 3.

For the second test case, the given binary tree is shown below.

As we are looking for node 1 which is itself the root node, hence our level is 1.
Sample Input 2:
1
1 3 8 5 -1 7 -1 -1 -1 -1 -1
10
Sample Output 2:
0
Explanation of Sample Input 2:
For the first test case, the given binary tree is shown below.

As node 10 is not present in the tree, so we return 0.*/

#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        bool isOriginal;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int cnt =0;
map<int,int>mp;
int nodeL(TreeNode<int>* root, int searchedValue,int level){
     queue<pair<TreeNode<int>*,int>>q;
     q.push({root,1});
     while(!q.empty()){
         pair<TreeNode<int>*,int> pr = q.front();
         TreeNode<int>* temp = pr.first;
         int level = pr.second;
         q.pop();

        if(temp->val == searchedValue){return level;}
        if(temp->left){
            q.push({temp->left,level+1});
        }
        if(temp->right){
            q.push({temp->right,level+1});
        }
     }  
}

int nodeLevel(TreeNode<int>* root, int searchedValue)
{
    // Write your code here.
    int level =0;
    return nodeL(root, searchedValue,level);
    
    

   
}
