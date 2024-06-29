//jay shree krishna
#include<bits/stdc++.h>
#include<list>
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
    int data;cin>>data;
    Node *head= NULL;
    Node *tail = NULL;
    while(data !=-1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        cin>>data;

    }
    return head;
}
// list<int> removeDuplicates(list<int> list1) {
//     list<int> unique_values;
//     for (int value : list1) {
//         if (unique_values.find(value) == unique_values.end()) {
//             unique_values.push_back(value);
//         }
//     }

//     return unique_values;
// }
int32_t main(){
    list<int>a={};

    Node *head = takeInput();
    Node *temp  = head;
    while(temp){
        a.push_back(temp->val);
        temp=temp->next;
    }
    
    a.sort();a.unique();

    for (int value : a) {
        cout << value << " ";
    }

    cout << endl;
   
return 0;}