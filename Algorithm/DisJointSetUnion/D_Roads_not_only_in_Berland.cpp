/*
linK: https://codeforces.com/contest/25/problem/D
Berland Government decided to improve relations with neighboring countries. First of all, it was decided to build new roads so that from each city of Berland and neighboring countries it became possible to reach all the others. There are n cities in Berland and neighboring countries in total and exactly n - 1 two-way roads. Because of the recent financial crisis, the Berland Government is strongly pressed for money, so to build a new road it has to close some of the existing ones. Every day it is possible to close one existing road and immediately build a new one. Your task is to determine how many days would be needed to rebuild roads so that from each city it became possible to reach all the others, and to draw a plan of closure of old roads and building of new ones.

Input
The first line contains integer n (2 ≤ n ≤ 1000) — amount of cities in Berland and neighboring countries. Next n - 1 lines contain the description of roads. Each road is described by two space-separated integers ai, bi (1 ≤ ai, bi ≤ n, ai ≠ bi) — pair of cities, which the road connects. It can't be more than one road between a pair of cities. No road connects the city with itself.

Output
Output the answer, number t — what is the least amount of days needed to rebuild roads so that from each city it became possible to reach all the others. Then output t lines — the plan of closure of old roads and building of new ones. Each line should describe one day in the format i j u v — it means that road between cities i and j became closed and a new road between cities u and v is built. Cities are numbered from 1. If the answer is not unique, output any.

Examples
inputCopy
2
1 2
outputCopy
0
inputCopy
7
1 2
2 3
3 1
4 5
5 6
6 7
outputCopy
1
3 1 3 7
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pii pair<int, int>
const int N = 1e5 + 7;

// Data structures for Disjoint Set Union (DSU)
vector<int> parent(N);
vector<int> Rank(N, 0);

// Vectors to store edges, MST, and repairs
vector<pii> mst;
vector<pii> repair;

int n, m;

// Node class to store edges
class node {
public:
  int u, v;
  node(int first, int second) : u(first), v(second) {}
};

vector<node> edges;

// Function to initialize DSU
void setParent(int n) {
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }
}

// Comparison function to sort edges by their first node
bool comp(node a, node b) {
  return a.u < b.u;
}

// Function to find the parent of a node with path compression
int findPar(int u, vector<int> &parent) {
  if (u == parent[u]) return u;
  return parent[u] = findPar(parent[u], parent);
}

// Function to union two sets by rank
void unionn(int u, int v, vector<int> &parent, vector<int> &rank) {
  u = findPar(u, parent);
  v = findPar(v, parent);
  if (rank[u] < rank[v]) {
    parent[u] = v;
  } else if (rank[v] < rank[u]) {
    parent[v] = u;
  } else {
    parent[v] = u;
    rank[u]++;
  }
}
vector<int>missingNodes;
// Function to implement Kruskal's algorithm
void kruskalAlgo(vector<node> &edges, vector<int> &parent) {
  for (auto it : edges) {
    int node1 = it.u;
    int node2 = it.v;
    if (findPar(node1, parent) == findPar(node2, parent)) {
      repair.push_back({node1, node2});
    } else {
      //mst.push_back({node1, node2});
      unionn(node1, node2, parent, Rank);
    }
  }
  for(int i=1;i<=n;i++){
        if(findPar(i,parent)==i){
            missingNodes.push_back(i);
        }
  }
}

int32_t main() {
  cin >> n;
  m = n - 1;
  setParent(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  sort(edges.begin(), edges.end(), comp);
  kruskalAlgo(edges, parent);

  cout << repair.size() << endl;
  for (int i = 0; i < repair.size(); i++) {
    int u = repair[i].first;
    int v = repair[i].second;
    cout<<u<<" "<<v<<" "<<missingNodes[i]<<" "<<missingNodes[i+1]<<endl;
  }
  return 0;
}

/*
#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) {
            return;
        }
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[px] = py;
            if (rank[px] == rank[py]) {
                rank[py]++;
            }
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    DSU dsu(n);
    vector<pair<int, int>> to_remove, to_add;
    for (auto [u, v] : edges) {
        if (dsu.find(u) != dsu.find(v)) {
            dsu.merge(u, v);
        } else {
            to_remove.push_back({u, v});
        }
    }

    set<int> components;
    for (int i = 1; i <= n; ++i) {
        components.insert(dsu.find(i));
    }

    auto it = components.begin();
    int root = *it;
    it++;
    for (; it != components.end(); ++it) {
        to_add.push_back({root, *it});
    }

    cout << to_remove.size() << endl;
    for (int i = 0; i < to_remove.size(); ++i) {
        cout << to_remove[i].first << " " << to_remove[i].second << " " << to_add[i].first << " " << to_add[i].second << endl;
    }
    return 0;
}
*/