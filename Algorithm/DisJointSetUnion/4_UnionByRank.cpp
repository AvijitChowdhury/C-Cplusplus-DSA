//optimization in union operation 
//utilizing the size of the set
//time complexity = O(logn)
//space complexity = O(n)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int parent[N+1];
int ParentLevel[N+1];

void dsu_set(int n){
    for(int i=1;i<=n;i++){
        parent[i] = -1;
        ParentLevel[i] = 0;
    }

}

int dsu_find(int n){
    if(parent[n]==-1){
        return n;
    }
    return dsu_find(parent[n]);
}

void dsu_union(int u,int v){
    int leaderA = dsu_find(u);
    int leaderB = dsu_find(v);
    if(leaderA!=leaderB){
        if(ParentLevel[leaderA]<ParentLevel[leaderB]){
            parent[leaderA] = leaderB;
            
        }else if(ParentLevel[leaderA]>ParentLevel[leaderB]){
            parent[leaderB] = leaderA;
            
        }else{
            parent[leaderA] = leaderB;
            ParentLevel[leaderB]++;
        }
        
    }
}



int32_t main(){
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    while(e--){
        int u,v;
        cin>>u>>v;
        dsu_union(u,v);
        for(int i=1;i<=n;i++){
            cout<<parent[i]<<" ";
        }
    }
    

}
