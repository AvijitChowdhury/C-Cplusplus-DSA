#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int>adj[N];
bool visited[N];
int level[N];
int parent[N];
//T.C : O(n+m)
//time complexity: O(n+m) means O(n)
void bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;
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
            parent[v] = u;
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
    //path finding complexity O(n)
    int s,d;
    cin>>s>>d;
    bfs(s);
    cout<<"Distance between "<<s<<" and "<<d<<" is: "<<level[d]<<endl;
    // for(int i=1;i<=m;i++){
    //     cout<<"Level of Node: "<<i<<" "<<level[i]<<" "<<endl;
    // }
    vector<int>path;
    int current = d;
    while(current!=-1){
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(),path.end());
    cout<<"Path: ";
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    
}