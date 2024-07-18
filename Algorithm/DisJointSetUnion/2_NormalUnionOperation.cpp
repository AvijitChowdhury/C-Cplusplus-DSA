//NOrmal union operation doesn't have any optimization
#include<bits/stdc++.h>
using namespace std;
int parent[8] = {-1,-1,1,1,6,4,-1,-1};
int dsu_find(int node){
    while(parent[node]!=-1){
        node = parent[node];
    }
    return node;
}

void dsu_union(int u,int v){
    
    
    int pu = dsu_find(u);
    int pv = dsu_find(v);
    
    if(pu!=pv){
        parent[pu] = pv;
    }
    
    cout<<endl;
}
//recursive approach
//time complexity = O(n)
int dsu_findRecursive(int n){
    if(parent[n]==-1){
        return n;
    }
    return dsu_findRecursive(parent[n]);
}
//recursive approach for union
//time complexity = O(n)
void dsu_unionRecursive(int u,int v){
    int pu = dsu_findRecursive(u);
    int pv = dsu_findRecursive(v);
    
    if(pu!=pv){
        parent[pu] = pv;
    }
}
int32_t main(){
    int n,e;
    cin>>e;
    
    while(e--){
        int u,v;
        cin>>u>>v;
        // cout<<u<<" "<<v<<endl;
        dsu_union(u,v);
        for(int i=1;i<=n;i++){
            cout<<parent[i]<<" ";
        }
    }
}