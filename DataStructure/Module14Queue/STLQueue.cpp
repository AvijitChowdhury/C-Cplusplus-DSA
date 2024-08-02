//jay shree krishna
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    queue<int>q;
    for(int i=10;i<=50;i+=10){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

return 0;}