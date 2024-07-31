/*
maximum coin you can take and make sum of given k
3
1 2 3
5
Output: 5
5 ways*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int dp[1001][1001];

int CoinChangeTopDown(int n, int s, int w[]) {
    if (n == 0) {
        return s == 0 ? 1 : 0;
    }
    if (dp[n][s] != -1) {
        return dp[n][s];
    }
    if (w[n-1] <= s) {
        return dp[n][s] = CoinChangeTopDown(n, s - w[n-1], w) + CoinChangeTopDown(n-1, s, w);
    } else {
        return dp[n][s] = CoinChangeTopDown(n-1, s, w);
    }
}

int coinChange(int n, int s, int w[]) {
    int dp[n + 1][s + 1];
    dp[0][0] = 1;

    for (int i = 1; i <= s; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (w[i - 1] <= j) {
                dp[i][j] = dp[i][j - w[i - 1]] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][s];
}

int32_t main() {
    int n;
    cin >> n;
    int w[n];
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    
    // Using the Top-Down approach
    cout << "Top-Down Approach: " << CoinChangeTopDown(n, s, w) << endl;

    // Using the Bottom-Up approach
    cout << "Bottom-Up Approach: " << coinChange(n, s, w) << endl;

    return 0;
}
