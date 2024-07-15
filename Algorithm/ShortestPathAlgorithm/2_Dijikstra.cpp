/*
INput: 
7
8
1 2 3
1 3 5
3 4 1
4 6 1
2 5 6
5 6 1
5 7 2
3 7 12
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pii pair<int,int>
const int N = 1e3+5;
vector<pii>adj[N];
vector<bool>visited(N);
vector<int>dist(N,INT_MAX);
void dijikstra(int source){
    priority_queue<pii,vector<pii>,greater<pii>>pq;
   //vector<int>dist(N,INT_MAX);
    visited[source] = true;
    dist[source] = 0;
    pq.push({dist[source],source});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(pii v: adj[u]){
            int dv = v.first;
            int weight = v.second;
            
            if(visited[dv]==true){
                continue;
            }
            if(dist[dv]>dist[u]+weight){
                dist[dv] = dist[u]+weight;
                pq.push({dist[dv],dv});
        }
    }

}}
int32_t main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v, w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int source;
    dijikstra(1);
    for(int i=1;i<=n;i++){
        cout<<"Distance of Node: "<<i<<" "<<dist[i]<<endl;
    }
}