/*
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5;
vector<int> dp(N,-1);

int fibo(int n)
{
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int32_t main()
{
    int n;
    cin >> n;
    fibo(n);
    
    cout << dp[n] << endl;
    return 0;
}