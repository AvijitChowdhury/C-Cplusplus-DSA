#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
bool visited[N];
vector<int> adj[N];
int cnt=0;
bool dfs(int u, int parent){
    bool cycleDetected = false;
    visited[u] = true;
    for(int v : adj[u]){
        if(v!=parent && visited[v]){
            return true;
        }
        cycleDetected = cycleDetected | dfs(v,u);
    }
    return cycleDetected;
}



int32_t main(){

int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    //adj[v].push_back(u);
    }
    bool isCycle = false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            isCycle |= dfs(i,-1);
        }
    }
    if(isCycle){
        cout<<"Cycle Detected"<<endl;
    }else{
        cout<<"No Cycle Detected"<<endl;
    }
    
    return 0;


}