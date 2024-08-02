#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int>adj[N];
bool visited[N];
vector<int> components;

void dfs(int u){
    visited[u] = true;
    components.push_back(u);
    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
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
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            components.clear();
            cnt++;
            dfs(i);
            cout<<"Component: ";
            for(auto node: components){
                cout<<node<<" ";
            }
            cout<<endl;
        }
    }
    cout<<"Number of Connected Components: "<<cnt<<endl;
}