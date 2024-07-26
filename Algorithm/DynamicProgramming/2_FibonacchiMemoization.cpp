/*
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5;
vector<int> dp(N,-1);

int fibo(int n)
{
    if (n == 0 || n == 1)
        return 1;
    //memoization
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=fibo(n-1)+ fibo(n-2);
}
int32_t main()
{
    int n;
    cin >> n;
    fibo(n);
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    cout << dp[n] << endl;
    return 0;
}