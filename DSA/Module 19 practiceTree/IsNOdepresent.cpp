/*
For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^5

Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec.
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7
Sample Output 1:
true
Explanation For Output 1:
Clearly, we can see that 7 is present in the tree. So, the output will be true.
Sample Input 2:
2 3 4 -1 -1 -1 -1
10
Sample Output 2:
false
*/
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool isNode(BinaryTreeNode<int> *root,int x,int cnt){

    if(root==NULL){return cnt;}
    if (root->data == x) {
      cnt =true;
      return true;
    }
    bool l = isNode(root->left,x,cnt);
    bool r= isNode(root->right,x,cnt);
    if(l){return l;}
    else if(r){return r;}
}
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
    bool cnt=0;
    return isNode(root,x,cnt);

}