/*
Find the minimum spanning tree of the graph.

Input
On the first line there will be two integers N - the number of nodes and M - the number of edges. (1 <= N <= 10000), (1 <= M <= 100000)
M lines follow with three integers i j k on each line representing an edge between node i and j with weight k. The IDs of the nodes are between 1 and n inclusive. The weight of each edge will be <= 1000000.

Output
Single number representing the total weight of the minimum spanning tree on this graph. There will be only one possible MST.

Example
Input:
4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40

Output:
17*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int 
#define pii pair<int,int>
const int N = 1e4+7;
vector<int> parent(N);
vector<int>Rank(N,0);
vector<pii> mst;

class node {
    public:
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};
vector<node> edges;
void setParent(int n){
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
}
bool comp(node a, node b){
    return a.wt<b.wt;
}

int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return  parent[u]=findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
    u = findPar(u, parent);
    v = findPar(v, parent);
    if(rank[u] < rank[v]) {
    	parent[u] = v;
    }
    else if(rank[v] < rank[u]) {
    	parent[v] = u; 
    }
    else {
    	parent[v] = u;
    	rank[u]++; 
    }
}
int mincost=0;
void kruksalAlgo(vector<node> &edges, vector<int> &parent){
    for(auto it : edges ){
        int node1 = it.u;
        int node2 = it.v;
        int wt = it.wt;
        if(findPar(node1,parent)!=findPar(node2,parent)){
            mincost+= wt;
            mst.push_back({node1,node2});
            unionn(node1,node2,parent,Rank);
        }

    }

}
int32_t main(){
    int n,m;
    cin>>n>>m;
    setParent(n);
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(),edges.end(),comp);
    kruksalAlgo(edges,parent);
    cout<<mincost<<endl;
}