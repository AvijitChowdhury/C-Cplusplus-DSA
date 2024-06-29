//jay shree krishna
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node(int val){
        this->val= val;
        this->next = NULL;
    }
};
Node *takeInput(){
    int val;cin>>val;
    Node *head= NULL;
    Node *tail = NULL;
    while(val !=-1){
        Node *newNode = new Node(val);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>val;

    }
    return head;
}
bool isPalindrome(Node* head) {

    stack<int> s;

    Node* curr = head;
    while (curr != nullptr) {
        s.push(curr->val);
        curr = curr->next;
    }

    curr = head;
    while (curr != nullptr) {
        int popped_element = s.top();
        s.pop();

        if (curr->val != popped_element) {
            return false;
        }

        curr = curr->next;
    }

    return true;
}
int32_t main(){
    Node *head = takeInput();
    if(isPalindrome(head)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

return 0;}