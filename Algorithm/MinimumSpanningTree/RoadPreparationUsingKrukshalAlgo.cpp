/*
/*
linK: https://cses.fi/problemset/task/1675/
There are n cities and m roads between them. Unfortunately, the condition of the roads is so poor that they cannot be used. Your task is to repair some of the roads so that there will be a decent route between any two cities.
For each road, you know its reparation cost, and you should find a solution where the total cost is as small as possible.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the roads. Each line has three integers a, b and c: there is a road between cities a and b, and its reparation cost is c. All roads are two-way roads.
Every road is between two different cities, and there is at most one road between two cities.
Output
Print one integer: the minimum total reparation cost. However, if there are no solutions, print "IMPOSSIBLE".
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n
1 \le c \le 10^9

Example
Input:
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4

Output:
14
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int 
#define pii pair<int,int>
const int N = 1e5+7;
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
    if(mst.size()!=n-1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    
    cout<<mincost<<endl;
}