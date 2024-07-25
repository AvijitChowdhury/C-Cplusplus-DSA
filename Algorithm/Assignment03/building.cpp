/*
link: https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03/challenges/building-3-1
You have just opened a ISP business and you want to connect your WIFI lines in your area. In your area there are  buldings and  roads connecting those buildings. The roads are two way obviously. In each road there is a cost of connecting the cables. You want to connect all buldings in such a way that there is connection from any building to another, not necessary to be directly.

As you are a businessman, you want the total cost to be minimum. Can you tell the minimum total cost to do the work?

Note: There can be multiple roads from one building to another. If it is not possible to connect all the building, print . Each building has a number from  to .

Input Format

First line will contain  and .
Next  lines will contain ,  and  which means there is a connection in between  and  where the cost for connecting the cable is .
Constraints

Output Format

Output the minimum cost.
Sample Input 0

5 7
1 2 10
1 3 5
3 2 4
2 4 1
3 4 2
4 5 3
1 5 2
Sample Output 0

8
Sample Input 1

3 2
1 2 10
2 1 2
Sample Output 1

-1*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
#define int long long int
#define pii pair<int,int>

vector<pii>adj[N];
vector<bool>visited(N,false);
vector<int>dist(N,INT_MAX);
//Time Complexity: O(ElogV) means O(nlogn)
int minCost =0;
//prims algorithm implementation
int parent[N]; 
int key[N]; 
bool mstSet[N]; 
void setKeyandMST(int n){
    for (int i = 1; i <= n; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
}

void primsAlgorithm(int start){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    key[start] = 0; 
    parent[start] = -1; 
    pq.push({0, start});
    minCost+=key[start];
    while(!pq.empty()){
        int unode = pq.top().second;
        pq.pop();
        if(mstSet[unode]==false){minCost+=key[unode];}       
        mstSet[unode] = true;
        for(auto it: adj[unode]){
            int vertex = it.first;
            int weight = it.second;
            if(mstSet[vertex] == false && weight < key[vertex]){
                //minCost+=weight;
                key[vertex] = weight;
                parent[vertex]  = unode;
                pq.push({weight,vertex});
            }
        }
    }
}
int32_t main(){
    int n,m;
    cin>>n>>m;
    setKeyandMST(n);
    while(m--){
        int node,v,w;
        cin>>node>>v>>w;
        adj[node].push_back({v,w});
        adj[v].push_back({node,w});
        
    }
    primsAlgorithm(1);
    for(int i=1;i<=n;i++){
        if(mstSet[i]==false){
            cout<<"-1";
            return 0;
        }
    }
    
    cout<<minCost<<endl;
}
