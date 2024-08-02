/*
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
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
int level[N];
void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        //pop a node from the queue adn insert
        //unvisited neighbours of the node into the queue
        int  u = q.front();
        cout<<"Visiting Node: "<<u<<endl;
        q.pop();
        //section 1: A node is being processed
        for(int v: adj[u]){
            //section 2: Child processing
            if(visited[v]==true){
                continue;
            }
            q.push(v);
            visited[v] = true;
            //section 3: Child processing  
            level[v] = level[u] + 1;
        }
        //section 4:same as section 1
    }
}

int32_t main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    bfs(1);
    for(int i=1;i<=m;i++){
        cout<<"Level of Node: "<<i<<" "<<level[i]<<" "<<endl;
    }
    
}