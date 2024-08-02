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
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
#define int long long int
#define pii pair<int,int>

vector<pii>adj[N];
vector<bool>visited(N,false);
vector<int>dist(N,INT_MAX);
//Time Complexity: O(ElogV) means O(nlogn)
int minCost =0;
void bfs(int s){
    priority_queue<pii,vector<pii>,greater<pii>>pq;

    pq.push({0,s});
    //visited[s] = true;
    
    while(!pq.empty()){
        //pop a node from the queue adn insert
        //unvisited neighbours of the node into the queue
        int  node = pq.top().second;
        int dis = pq.top().first;
        //cout<<"Visiting Node: "<<node<<endl;
        //cout<<"Visiting Node: "<<node<<endl;
        if(visited[node]){         
            pq.pop();
            continue;
        }
        minCost+=dis;
        visited[node] = true;
        pq.pop();
        //section 1: A node is being processed
        for(auto vpair: adj[node]){
            int v = vpair.first;
            int wt = vpair.second;
            
            //section 2: Child processing
            if(!visited[v]){
                
                pq.push({wt,v});
            }
        }
        //section 4:same as section 1
    }
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int node,v,w;
        cin>>node>>v>>w;
        adj[node].push_back({v,w});
        adj[v].push_back({node,w});
        
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    //minCost = dist[n];
    cout<<minCost<<endl;
}
