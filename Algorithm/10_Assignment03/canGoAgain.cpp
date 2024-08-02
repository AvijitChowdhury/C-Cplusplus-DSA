/*
link:https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03/challenges/can-go-again*/
#include <bits/stdc++.h>
using namespace std;

#define int long long int
const int N = 1005;
#define pii pair<int, int>
const int INF = 1e18;  // Adjusted INF for long long
vector<pii> g[N];
vector<pair<pii, int>> list_of_edges;
vector<int> dist(N, INF);
int n, m;

// T.C = O(n*m) if n==m then O(n^2)
void bellmanford(int start) {
    dist[start] = 0;
    for (int i = 1; i < n; i++) {
        for (auto edge : list_of_edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int w = edge.second;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
}

bool check_negative_cycle() {
    for (auto edge : list_of_edges) {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return true;
        }
    }
    return false;
}

int32_t main() {
    cin >> n >> m;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        list_of_edges.push_back({{u, v}, w});
    }
    int source;
    cin >> source;

    bellmanford(source);

    if (check_negative_cycle()) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;
    while (t--) {
        int destination;
        cin >> destination;
        if (dist[destination] == INF) {
            cout << "Not Possible" << endl;
        } else {
            cout << dist[destination] << endl;
        }
    }
    return 0;
}
