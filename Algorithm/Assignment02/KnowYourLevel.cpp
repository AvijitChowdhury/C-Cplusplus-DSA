/*
//problem link: https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-03/challenges/know-your-level
Problem
Zaman lives in a city of pizzas where every street has several pizza shops and everyone loves pizza there. Suppose there are N pizza shops in Zaman's area. All pizza shops have unique numbers written in the shop, the number of the first pizza shop in his city is from 0 to 10^5. There are E roads between pizza shops, and these pizza shops form a undirected connected graph where you can divide them in levels where the level starts from 0. Zaman lives in level L, now he wants to know which pizza shops are there in his level. Can you help him to get the desired pizza shops?

Note: If there are no pizza shops at level L, then print -1.

Input Format

First line will contain two integers N and E, number of pizza shops and roads repectively.
The next E lines will contain two integeres A and B, which means there is a road between A and B.
The last line will contain L, the level where Zaman lives.
Constraints

0 < N <= 10^5
1 <= E <= 10^5
0 <= A, B, L <= 10^5
Output Format

Output the numbers written on the pizza shops that are in level L in ascending order.
Sample Input 0

3 2
0 1
0 2
1
Sample Output 0

1 2 */
#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 100005;


vector<int> adj[N];
vector<int> level(N);

void bfs(int start) {
    queue<int> q;
    q.push(start);
    level[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (level[v] == -1) {
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    // Initialize shop levels
    fill(level.begin(), level.end(), -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int targetLevel;
    cin >> targetLevel;
    if(targetLevel==0){
        cout<<0<<endl;
        return 0;
    }

    bfs(0); 

    
    vector<int> v;
    for (int shop = 0; shop < N; ++shop) {
        if (level[shop] == targetLevel) {
            v.push_back(shop);
            
        }
    }
    //sort(v.begin(), v.end());
    if (v.empty()) {
        cout << -1 << endl;
    } else {
        for (int shop : v) {
            cout << shop << " ";
        }
        cout << endl;
    }
   
    

    return 0;
}
