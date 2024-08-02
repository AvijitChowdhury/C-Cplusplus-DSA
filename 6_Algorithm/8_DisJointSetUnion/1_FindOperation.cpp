#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;  
const int N = 1e3+7;
int parent[8] = {-1,-1,1,1,6,4,-1,-1};
int find(int n){
    while(parent[n]!=-1){
        n = parent[n];
    }
    return n;
}
//recursive approach
//time complexity = O(n)
int findRecursive(int n){
    if(parent[n]==-1){
        return n;
    }
    return findRecursive(parent[n]);
}
int32_t main(){
    // cout<<find(5)<<endl;
    // cout<<find(6)<<endl;
    // cout<<find(1)<<endl;
    // cout<<find(2)<<endl;
    // cout<<find(3)<<endl;
    // cout<<find(4)<<endl;
    cout<<find(7)<<endl;
    cout<<findRecursive(7)<<endl;
    // cout<<find(8)<<endl;
    return 0;
}