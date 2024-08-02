/*
link: https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03/challenges/cycle-of-edges*/
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5+5;
// bool visited[N];
// vector<int> adj[N];
// vector<int>parent[N];
// int cnt=0;
// // Remove the redeclaration of cnt inside the main function
// bool dfs(int u, int parent){
//     int  cycleDetected = false;
//     visited[u] = true;
//     for(int v : adj[u]){
//         if(v!=parent && visited[v]){
//             cnt++;
//             return true;
//         }    
//          cycleDetected = cycleDetected | dfs(v,u);
//        // cnt+=dfs(v,u);
//     }
//     return cycleDetected;
// }


// int32_t main(){
//     int n,m;
//     cin>>n>>m;

//     while(m--){
//         int u,v;
//         cin>>u>>v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
    
    
//     int cycle =0;
//     for(int i=1;i<=n;i++){
//         if(!visited[i]){
        
//         dfs(i,-1);
//         }
        
//     }
//     cout<<cnt<<endl;

// }
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
int cnt=0;


int32_t main(){
    int n,e;
    cin>>n>>e;
    dsu_set(n);
    while(e--){
        int u,v;
        cin>>u>>v;
        int leaderA = dsu_find(u);
        int leaderB = dsu_find(v);
        if(leaderA==leaderB){
            cnt++;
            
        }else{dsu_union(u,v);}
        
        
    }
    cout<<cnt<<endl;
    

}