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

Output:
Visiting Node: 1
Visiting Node: 2
Visiting Node: 4
Visiting Node: 5
Visiting Node: 6
Visiting Node: 8
Visiting Node: 7
Visiting Node: 3
Visiting Node: 9
Visiting Node: 10
Visiting Node: 11
Visiting Node: 12
Depth of Node: 1 0 
Depth of Node: 2 1 
Depth of Node: 3 1 
Depth of Node: 4 2 
Depth of Node: 5 2 
Depth of Node: 6 3 
Depth of Node: 7 3 
Depth of Node: 8 4 
Depth of Node: 9 2 
Depth of Node: 10 1 
Depth of Node: 11 2 
Depth of Node: 12 2 
height of Node: 1 2 
height of Node: 2 2 
height of Node: 3 1 
height of Node: 4 0 
height of Node: 5 1 
height of Node: 6 1 
height of Node: 7 0 
height of Node: 8 0 
height of Node: 9 0 
height of Node: 10 1 
height of Node: 11 0 
height of Node: 12 0 
List 1: (2) (3) (10) 
List 2: (1) (4) (5) 
List 3: (1) (9) 
List 4: (2) 
List 5: (2) (6) (7) 
List 6: (5) (8) 
List 7: (5) 
List 8: (6) 
List 9: (3) 
List 10: (1) (11) (12) 
List 11: (10) 
List 12: (10) 
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