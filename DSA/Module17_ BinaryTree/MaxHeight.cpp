    

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
void preorderTranverse(Node *node){
    if(node==NULL){
        return;
    }
    cout<<node->val<<"--";
    preorderTranverse(node->left);
    preorderTranverse(node->right);
    
};
void postorderTranverse(Node *node){
    
    if(node==NULL){
        return;
    }
    
    postorderTranverse(node->left); 
      
    postorderTranverse(node->right);
    cout<<node->val<<"--";
}
void INorderTranverse(Node *node){
    
    if(node==NULL){
        return;
    }
    
    INorderTranverse(node->left); 
    cout<<node->val<<"--";
    INorderTranverse(node->right);
    
}
int countNode(Node *root){
    if(root==NULL){return 0;}
    int l= countNode(root->left);
    int r= countNode(root->right);
    return l+r+1;
}
int leafNode(Node *root){
    if(root==NULL)return 0;
    if(root->left ==NULL &&root->right==NULL){return 1;}
    else{
    int l= countNode(root->left);
    int r=countNode(root->right);
    return l+r;
    }
}
int maxHeight(Node *root){
    if(root==NULL){
        return 0;
    }
    int l=maxHeight(root->left);
    int r=maxHeight(root->right);
    return max(l,r)+1;
}
void leveOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        cout << f->val << "--";
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
int32_t main(){


    //Connections
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);
    Node *i = new Node(100);
    //connections
    root->left = a;
    root->right =b ;
    a->left = c;a->right=h;
    c->right= e;h->right=i;
    b->right=d;d->left= f;d->right=g;
    preorderTranverse(root);cout<<endl;
    postorderTranverse(root);cout<<endl;
    INorderTranverse(root);cout<<endl;

    int Nodecnt= countNode(root);
    cout<<Nodecnt<<endl;
    int leafNodecnt=leafNode(root);
    cout<<leafNodecnt<<endl;

}


