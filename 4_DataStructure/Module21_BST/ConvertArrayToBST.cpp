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
Node *convert(int a[],int n,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    Node *root = new Node(a[mid]);
    root->left = convert(a,n,start,mid-1);
    root->right = convert(a,n,mid+1,end);
    return root;
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   Node *root = convert(a,n,0,n-1);
   levelOrder(root);

    return 0;
}