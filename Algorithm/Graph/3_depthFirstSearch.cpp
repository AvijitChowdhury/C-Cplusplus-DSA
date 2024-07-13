/*
INput:
4
5 
1 2 8
1 3 9
2 4 11
4 3 17
3 2 15
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<pair<int,int>> adj[N];
bool visited[N];
void dfs(int u){
    //section 1: actions just after entering a node
    visited[u] = true;
    cout<<"Visiting Node: "<<u<<endl;
    for(auto v: adj[u]){
        //section 2: actions before entering a new neighbour
        if(!visited[u]){
            dfs(v);
        }
        //section 3: actions after exiting a neighbour
    }
    //section 4: actions before exiting node u
}
int32_t main(){
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back(v;
    //adj[v]
}
dfs(1);
for(int i=1;i<=n;i++){
    cout<<"List "<<i<<": ";
    for(auto j:adj[i]){
        cout<<"("<<j<<") ";
    }cout<<endl;
}
}