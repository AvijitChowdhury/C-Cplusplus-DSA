/*
link: https://cses.fi/problemset/task/1676
There are n cities and initially no roads between them. However, every day a new road will be constructed, and there will be a total of m roads.
A component is a group of cities where there is a route between any two cities using the roads. After each day, your task is to find the number of components and the size of the largest component.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the new roads. Each line has two integers a and b: a new road is constructed between cities a and b.
You may assume that every road will be constructed between two different cities.
Output
Print m lines: the required information after each day.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
1 2
1 3
4 5

Output:
4 2
3 3
2 3
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int parent[N];
int ParentSize[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        ParentSize[i] = 1;
    }
}



int dsu_find(int n){
    if(parent[n]==-1){
        return n;
    }
    return dsu_find(parent[n]);
}
int mx=0;
void dsu_union(int u,int v){
    int leaderA = dsu_find(u);
    int leaderB = dsu_find(v);
    if(leaderA!=leaderB){
        if(ParentSize[leaderA]<ParentSize[leaderB]){
            parent[leaderA] = leaderB;
            ParentSize[leaderB]+=ParentSize[leaderA];
            mx = max(mx, ParentSize[leaderB]);
        }else{
            parent[leaderB] = leaderA;
            ParentSize[leaderA]+=ParentSize[leaderB];
            mx = max(mx, ParentSize[leaderA]);
        }
        
    }
}


int32_t main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    int components=n;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        int leaderA= dsu_find(u);
        int leaderB = dsu_find(v);
        if(leaderA!=leaderB){
            dsu_union(u, v);
            components--;
        }
        
        
        cout<<components<<" "<<mx<<endl;
        
    }
   
    
    
}