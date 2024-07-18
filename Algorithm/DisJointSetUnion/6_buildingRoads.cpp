/*
link: https://cses.fi/problemset/task/1666
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
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int parent[N + 1];
int ParentLevel[N + 1];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        ParentLevel[i] = 0;
    }
}
int find(int n)
{
    if(parent[n]==-1){
        return n;
    }
    return find(parent[n]);
}
void dsu_union(int u, int v)
{
    int leaderA = find(u);
    int leaderB = find(v);
    if (leaderA != leaderB)
    {
        if (ParentLevel[leaderA] == ParentLevel[leaderB])
        {
            parent[leaderA] = leaderB;
            ParentLevel[leaderB]++; // Increment the level of the new leader (leaderB)
        }
        else if (ParentLevel[leaderA] < ParentLevel[leaderB])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
        }
    }
}
int32_t main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);

    while (e--)
    {
        int u, v;
        cin >> u >> v;
        dsu_union(u, v);
    }
    map<int, bool>mp;
    for (int i = 1; i <= n; i++)
    {
        mp[find(i)] = true;
    }
    cout << mp.size() - 1 << endl;
    vector<int>ans;
    for(auto i:mp){
        
        ans.push_back(i.first);
    }
    for(int i=1;i<ans.size();i++){
        cout<<ans[i-1]<<" "<<ans[i]<<endl;
    }
    
    
}