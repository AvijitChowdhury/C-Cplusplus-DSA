/*
link: https://cses.fi/problemset/task/1666
Time limit: 1.00 s
Memory limit: 512 MB



Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int M = 2e5+5;
vector<int>adj[N];
vector<bool>visited(N,false);

void dfs(int start){
    visited[start] = true;
    for(int v: adj[start]){
        if(visited[v]==false){dfs(v);}
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
    for(int i=1;i<=n;i++){
        if(visited[i]==false){
            dfs(i);
            v.push_back(i);
        }
    }
    cout<<v.size()-1<<endl;
    for(int i=1;i<v.size();i++){
        cout<<v[i-1]<<" "<<v[i]<<endl;
    }

}