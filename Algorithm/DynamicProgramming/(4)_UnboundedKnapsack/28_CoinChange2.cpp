/*
3
1 2 3
5
output:2
dp table: 
0 2147483646 2147483646 2147483646 2147483646 2147483646 
0 1 2 3 4 5 
0 1 1 2 2 3 
0 1 1 1 2 2
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
//min no of coins to make sum s
int dp[1001][1001];
int CoinChange2TD(int n, int s, int w[]){
    if(n==0){
        if(s==0){
            return 0;
        }else{
        return INT_MAX-1;
    }}
    if(dp[n][s]!=-1){
        return dp[n][s];
    }
    if(w[n-1]<=s){
        return dp[n][s]=min(1+CoinChange2TD(n,s-w[n-1],w),CoinChange2TD(n-1,s,w));}
        else{
            return dp[n][s]=CoinChange2TD(n-1,s,w);
        }
    return dp[n][s];

}
int CoinChange2BU(int n, int s, int w[]){
    int dp[n + 1][s + 1];
    dp[0][0]=0;
    for (int i = 1; i <= s; i++)
        dp[0][i] = INT_MAX-1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - w[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][s];
}
int32_t main(){
    int n;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int s;
    cin >> s;
    memset(dp,-1,sizeof dp);
    cout<<CoinChange2TD(n,s,coins);
    return 0;
}
/*
link: https://leetcode.com/problems/coin-change/
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/
/*
class Solution {
public:
//     int dp[1001][1001];
// int CoinChange2TD(int n, int s, vector<int>&w){
//     if(n==0){
//         if(s==0){
//             return 0;
//         }else{
//         return INT_MAX-1;
//     }}
//     if(dp[n][s]!=-1){
//         return dp[n][s];
//     }
//     if(w[n-1]<=s){
//         return dp[n][s]=min(1+CoinChange2TD(n,s-w[n-1],w),CoinChange2TD(n-1,s,w));}
//         else{
//             return dp[n][s]=CoinChange2TD(n-1,s,w);
//         }
//     return dp[n][s];

//     }
    int CoinChange2BU(int n, int s, vector<int>&w){
    int dp[n + 1][s + 1];
    dp[0][0]=0;
    for (int i = 1; i <= s; i++)
        dp[0][i] = INT_MAX-1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = min(1 + dp[i][j - w[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=s;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return dp[n][s];
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int sum=coins[0];
        if(n==1){
            if(amount%sum!=0){
                return -1;
            }
        }
        // memset(dp,-1,sizeof dp);
        int ans=CoinChange2BU(coins.size(),amount,coins);
        if(ans==INT_MAX-1){return -1;}else{return ans;};
    }
};*/