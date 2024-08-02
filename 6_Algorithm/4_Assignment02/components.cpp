/*
link: https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-03/challenges/components-4
You will be given an undirected graph as input. You need to tell the number nodes in each component in ascending order.

Note: There will be no component with single node.

Input Format

First line will contain N, the number of nodes and E, the number of edges. The value of nodes will be from 0 to 1000.
Next E lines will contain A, B which means there is a edge between node A and B.
Constraints

1 <= N, E <= 1000
Output Format

Output the number of nodes in each component in ascending order.
Sample Input 0

9 7
0 1
1 2
0 2
2 3
4 5
5 7
8 9
Sample Output 0

2 3 4 
Explanation 0

The components are shown for the sample test case:
image

Sample Input 1

5 3
999 1000
100 500
500 600
Sample Output 1

2 3*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> adj[N];
bool visited[N] = {false};

void dfs(int start, int &count) {
    visited[start] = true;
    count++;
    //cout << "Visiting node: " << start << endl; 
    for (int v : adj[start]) {
        if (!visited[v]) {
            dfs(v, count);
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    vector<int>nodes;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        nodes.push_back(u);nodes.push_back(v);
    }

    vector<int> componentSizes;
    for (auto it:nodes ) {
        if (!visited[it]) {
            int count = 0;
            dfs(it, count);
            if (count > 1) {
                componentSizes.push_back(count);
            }
        }
    }

    sort(componentSizes.begin(), componentSizes.end());
    for (int size : componentSizes) {
        cout << size << " ";
    }
    cout << endl;
    return 0;
}
