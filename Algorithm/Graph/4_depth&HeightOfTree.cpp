/*
INput:
12
11
1 2
1 3
1 10
2 4
2 5
3 9
5 6
5 7
6 8
10 11
10 12
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];
int depth[N],height[N];
void dfs(int u){
    //section 1: actions just after entering a node
    visited[u] = true;
    
    cout<<"Visiting Node: "<<u<<endl;
    for(int v: adj[u]){
        //section 2: actions before entering a new neighbour
        if(visited[v]==true){
            continue;
        }
        depth[v] = depth[u] + 1;
        dfs(v);
        //section 3: actions after exiting a neighbour
        if(height[v]+1>height[u]){
            height[u] = height[u] + 1;
        }
        //alternative
        //height[u] = max(height[u], height[v] + 1);
    }
    //section 4: actions before exiting node u
}
int32_t main(){
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
    int u,v,w;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    //adj[v]
}
dfs(1);
for(int i=1;i<=n;i++){
    cout<<"Depth of Node: "<<i<<" "<<depth[i]<<" "<<endl;
}
for(int i=1;i<=n;i++){
    cout<<"height of Node: "<<i<<" "<<height[i]<<" "<<endl;
}
for(int i=1;i<=n;i++){
    cout<<"List "<<i<<": ";
    for(auto j:adj[i]){
        cout<<"("<<j<<") ";
    }cout<<endl;
}
}