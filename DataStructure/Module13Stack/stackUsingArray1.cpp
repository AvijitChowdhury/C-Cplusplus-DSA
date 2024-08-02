//jay shree krishna
#include<bits/stdc++.h>
using namespace std;
class myStack{
    public:
    vector<int>v;
    void push(int val){
        v.push_back(val);
    }
    void pop(){
        v.pop_back();
    }
    int top(){
       return v.back();
    }
    int size(){
        return v.size();
    }
    bool empty(){
        if(v.size()==0)return true;
        else return false;
    }
};
int32_t main(){
    myStack newStack;
    newStack.push(4);
    cout<<newStack.top()<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        newStack.push(i);
    }
    while(!newStack.empty()){
        cout<<newStack.top()<<endl;
        newStack.pop();
    }

return 0;}