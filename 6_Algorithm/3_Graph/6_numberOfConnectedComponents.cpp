#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];
vector<vector<int>> components;

void dfs(int u, int comp_idx) {
    visited[u] = true;
    components[comp_idx].push_back(u);
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v, comp_idx);
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u); // uncomment for undirected graph
    }

    int cc = 0;
    int k=0,l=0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components.push_back(vector<int>());
            dfs(i, cc);
            cc++;k++;
            
        }
    }
    int i=1;
    cout << "Number of Connected Components: " << cc << endl;
    for (auto component : components) {
        cout<<"Number of Component "<<i<<": ";
        for (auto node : component) {
            cout <<node << " ";
        }
        i++;
        cout << endl;
    }

    return 0;
}

/*
INput:
7
5
1 2
1 3
2 3
2 4
5 6

OUtput:
Number of Connected Components: 3
Number of Component 1: 1 2 3 4 
Number of Component 2: 5 6 
Number of Component 3: 7 
*/