/*
You will be given an undirected graph as input. You will be given a query Q, for each query you will be given a source S and a destination D. You need to tell the minimum distance from source to destination for each query.

Note: If there is no path in between the source and destination, print -1.

Input Format

First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 10^5.
Next E lines will contain A, B which means there is a edge between node A and B.
Next line will contain Q, the number of queries.
For each query every line will contain S and D.
Constraints

1 <= N, E <= 1000
1 <= Q <= 1000
0 <= S, D <= 10^5
Output Format

Output the minimum distance from source to destination for each query.
Sample Input 0

6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
6
0 5
1 5
2 5
2 3
1 4
0 0
Sample Output 0

2
3
3
2
2
0*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];

int shortestPath = -1;

int  bfs(int start, int d) {
    bool visited[N] = {false};
    int dist[N] ={0};
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front().first;
        //
        q.pop();
        if (u == d) {
            return dist[u];
        }
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u]+ 1;
                q.push({v, dist[v]});
            }
        }
    }
    return -1;
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;
    while (q--) {
        int start, d;
        cin >> start >> d;
        //shortestPath = INT_MAX;
        
        if (bfs(start, d) ==-1) {
            cout << -1 << endl;
        } else {
            cout << bfs(start, d) << endl;
        }
    }

    return 0;
}
