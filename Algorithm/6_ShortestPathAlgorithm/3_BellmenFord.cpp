/*
INput:
7
10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
4 7 3
Output:
Distance of 1 :0
Distance of 2 :1
Distance of 3 :3
Distance of 4 :5
Distance of 5 :0
Distance of 6 :4
Distance of 7 :3
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N  = 1e5+5;
const int INF = 1e9+5;
vector<pii> g[N];
vector<pair<pii,int>>list_of_edges;
int dist[N];
int n,m;
//T.C = O(n*m) if n==m then O(n^2)
void bellman_ford(int start){
    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }
    dist[start] =0;
    for(int i=1;i<n;i++){
        //relax all edges for (n-1) times
        for(int u =1;u<=n;u++){
            for(auto edge: g[u]){
                int v = edge.first;
                int w = edge.second;
                if(dist[u]!=INF&&dist[u]+w<dist[v]){
                    dist[v] = dist[u]+w;
                }
            }
        
        }
    }
}
void bellmanford2(int start){
    for(int i=1;i<=n;i++){
        dist[i] = INF;
    }
    dist[start] = 0;
    for(int i=1;i<=n;i++){
        for(auto edge: list_of_edges){
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if(dist[u]!=INF&&dist[u]+w<dist[v]){
                dist[v] = dist[u]+w;
            }
        }
    }

}

int32_t main(){
    
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        list_of_edges.push_back({{u,v},w});
    }
    bellmanford2(1);
    for(int i=1;i<=n;i++){
        cout<<"Distance of "<<i<<" :"<<dist[i]<<endl;
    }
}