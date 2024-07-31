/*
Input:
4 6
5 3 2 4
4 1 3 2
OUtput:18

3 5
5 3 2
4 5 3
output: 5*/
/*
dp table:
0 0 0 0 0 0 
0 0 0 0 5 5 
0 0 0 0 5 5 
0 0 0 2 5 5 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int unboundedKnapsack(int n, int s, int val[], int weight[]){
    int dp[n+1][s+1];
    for (int i = 0; i <= n; i++){ 
        for (int j = 0; j <= s; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(weight[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]= dp[i-1][j];
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
    int n,s;
    cin>>n>>s;
    int val[n],weight[n];
    
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<unboundedKnapsack(n,s,val,weight);

}