/*
link:https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03/challenges/shortest-distance-2
You'll be given a graph of  nodes and  edges. For each edge, you'll be given ,  and  which means there is an edge from  to  only and which will cost .

Also, you'll be given  queries, for each query you'll be given  and , where  is the source and  is the destination. You need to print the minimum cost from  to  for each query. If there is no connection between  and , print .

Note: There can be multiple edges from one node to another. Make sure you handle this one.

Input Format

First line will contain  and .
Next  lines will contain ,  and .
After that you'll get .
Next  queries will contain  and .
Constraints

Output Format

Output the minimum cost for each query.
Sample Input 0

4 7
1 2 10
2 3 5
3 4 2
4 2 3
3 1 7
2 1 1
1 4 4
6
1 2
4 1
3 1
1 4
2 4
4 2
Sample Output 0

7
4
6
4
5
3
Sample Input 1

4 4
1 2 4
2 3 4
3 1 2
1 2 10
6
1 2
2 1
1 3
3 1
2 3
3 2
Sample Output 1

4
6
8
2
4
6*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 100;
#define pii pair<int, int>
int d[N][N];
int n,m;
const int INF = 1e18;


void dist_initialized(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                d[i][j] = 0;
            }else{
                d[i][j] = INF;
            }
        }
    }
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    dist_initialized();
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v],w);
    }

    int q;
    cin >> q;
    //T.C = O(n^3)
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(d[i][k]<INF&&d[k][j]<INF){
                    d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
    }
    while (q--) {
        int source, destination;
        cin >> source >> destination;
        if (d[source][destination] == INF)
            cout << -1 << endl;
        else
            cout << d[source][destination] << endl;
    }

    return 0;
}