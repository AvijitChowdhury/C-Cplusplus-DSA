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
        return dp[n][s]=min(1LL+CoinChange2TD(n,s-w[n-1],w),CoinChange2TD(n-1,s,w));}
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
    int w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int s;
    cin >> s;
    memset(dp,-1,sizeof dp);
    cout<<CoinChange2TD(n,s,w);
    return 0;
}