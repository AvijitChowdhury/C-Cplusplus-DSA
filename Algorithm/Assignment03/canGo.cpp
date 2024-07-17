/*
You will be given  numbers of nodes,  numbers of edges in a graph. For each edge you will be given ,  and  which means there is a connection from  to  only and for which you need to give  cost. The value of nodes could be from  to .

You will be given a start node . Then you will be given a test case , for each test case you will be given a destination node  and a cost . You need to tell if you can go to the destination from start using atmost  cost.

Input Format

First line will contain  and .
Next  lines will contain ,  and .
Next line will contain start node .
Next line will contain , the number of test cases.
For each test case, you will get  and .
Constraints

Output Format

Ouput "YES" or "NO" for each test case if it is possible to go from  to  using atmost  cost.
Sample Input 0

5 7
1 2 10
1 3 2
3 2 1
2 4 7
3 4 2
4 5 5
2 5 2
1
5
1 0
2 5
3 1
4 4
5 6
Sample Output 0

YES
YES
NO
YES
YES*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int 
const int N = 1e3+5;
vector<pair<int,int>>adj[N];
vector<bool>visited(N,false);
vector<int>dist(N,INT_MAX);
void dijikstra(int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
   //vector<int>dist(N,INT_MAX);
    visited[start] = true;
    dist[start] = 0;
    pq.push({dist[start],start});
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(pair<int,int> v: adj[u]){
            int dv = v.first;
            int wt = v.second;          
            if(dist[dv]>dist[u]+wt &&!visited[dv]){
                dist[dv] = dist[u]+wt;
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
        //adj[v].push_back({u,w});
    }
    int start;
    cin>>start;
    int t;
    cin>>t;
    while(t--){
        int dest, cost;
        cin>>dest>>cost;
        dijikstra(start);
        if(dist[dest]<=cost){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}