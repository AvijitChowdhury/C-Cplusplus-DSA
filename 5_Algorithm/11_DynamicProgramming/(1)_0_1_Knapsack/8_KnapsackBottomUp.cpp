/*
INput:
n: 1 2 3 4
value: 1 5 3 2 
wt: 5 2 4 3*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int dp[N][N];

//time complexity: O(n*w)
int knapsack(vector<int>& value, vector<int>& weight, int &n, int &w) {
    
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=w;j++){
    //         if(i==0||j==0){
    //         dp[i][j]=0;
    //         }
    //     }
    // }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            //base case
            if(i==0||j==0){
            dp[i][j]=0;
            }
            
            if(weight[i-1]<=j){
                dp[i][j] = max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
        }else{
            dp[i][j]=dp[i-1][j];
        }
    }
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            cout<<dp[i][j]<<" ";
        
        }cout<<endl;
    }
   return dp[n][w];
    
}

int32_t main() {
    //n measns number of items or index of items
    int n;
    cin >> n;
    vector<int> value(n);
    vector<int> weight(n);

    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    int w;
    cin >> w;
    //memset(dp, -1, sizeof(dp)); // Initialize dp array
    cout << knapsack(value, weight, n, w);
}
