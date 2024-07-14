#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

vector<int> adj[N];
vector<bool> visited(N, false);
vector<int> neighbours(N); // Store the number of neighbors for each house

void dfs(int start) {
    visited[start] = true;
    for (int v : adj[start]) {
        if (!visited[v]) {
            
            dfs(v);
            
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k;
    cin >> k;

    //dfs(k);

    cout << adj[k].size() << endl;

    return 0;
}
