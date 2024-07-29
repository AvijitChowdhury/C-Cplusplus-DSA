#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int dp[N][N];

//time complexity: O(n*w)
int knapsack(vector<int>& value, vector<int>& weight, int n, int w) {
    if (n == 0 || w == 0) {
        return 0;
    }
    if (dp[n][w] != -1) {
        return dp[n][w];
    }

    if (weight[n - 1] <= w) {
        int left = value[n - 1] + knapsack(value, weight, n - 1, w - weight[n - 1]);
        int right = knapsack(value, weight, n - 1, w);
        return dp[n][w]= max(left, right);
    } else {
        return dp[n][w]= knapsack(value, weight, n - 1, w);
    }
    
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
    memset(dp, -1, sizeof(dp)); // Initialize dp array
    cout << knapsack(value, weight, n, w);
}
