//optimization in union operation 
//utilizing the size of the set
//time complexity = O(logn)
//space complexity = O(n)
#include<bits/stdc++.h>
using namespace std;
int parent[n+1];
int ParentSize[n+1];


void dsu_find(int n){
    if(parent[n]==-1){
        return n;
    }
    return dsu_find(parent[n]);
}

void dsu_union(int u,int v){
    int leaderA = dsu_find(u);
    int leaderB = dsu_find(v);
    if(leaderA!=leaderB){
        if(ParentSize[leaderA]<ParentSize[leaderB]){
            parent[leaderA] = leaderB;
            ParentSize[leaderA]+=ParentSize[leaderB];
        }else{
            parent[leaderB] = leaderA;
            ParentSize[leaderB]+=ParentSize[leaderA];
        }
        
    }
}



int32_t main(){
    int n,e;
    cin>>n>>e;
    memset(parent,-1,sizeof(parent));
    memset(ParentSize,1,sizeof(ParentSize));
    while(e--){
        int u,v;
        cin>>u>>v;
        dsu_union(u,v);
        for(int i=1;i<=n;i++){
            cout<<parent[i]<<" ";
        }
    }
    

}
