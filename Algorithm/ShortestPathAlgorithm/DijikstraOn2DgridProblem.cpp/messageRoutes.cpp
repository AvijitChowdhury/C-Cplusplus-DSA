/*
The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.
Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int M = 2e5+5;
vector<int>adj[N];
vector<bool>visited(N,false);
vector<int> parent(N);
void bfs(int start){
    queue<int>q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v: adj[u]){
            if(visited[v]== false){
                q.push(v);
                visited[v] = true;
                parent[v]= u;
            }
        }
    }

}
int32_t main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>v;
    parent[1] = -1;
    bfs(1);
    if(visited[n]==false){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int current = n;
    while(current!=-1){
        v.push_back(current);
        current = parent[current];
    }
    reverse(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}