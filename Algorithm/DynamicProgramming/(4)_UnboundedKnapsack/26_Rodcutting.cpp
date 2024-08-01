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
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int unboundedKnapsack(int n, int s, int val[], int weight[]){
    int dp[n+1][s+1];
    dp[0][0]=1;
    for(int i=0;i<=s;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(weight[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    return dp[n][s];
}
int dp[1001][1001]={-1};
int unboundedKnapsackTD(int n, int s, int val[], int weight[]){
    if(n==0||s==0){
        return 0;
    }
    if(dp[n][s]!=-1){
        return dp[n][s];
    }
    if(weight[n-1]<=s){
        int op1=val[n-1]+unboundedKnapsackTD(n,s-weight[n-1],val,weight);
        int op2 = unboundedKnapsackTD(n-1,s,val,weight);
        return dp[n][s]=max(op1,op2);
    }else{
        return dp[n][s]=unboundedKnapsackTD(n-1,s,val,weight);
    }
}
int32_t main(){
    int n;
    cin>>n;
    int val[n],weight[n];
    
    for(int i=0;i<n;i++){
        cin>>val[i];
        weight[i]=i+1;
    }
    
    cout<<unboundedKnapsack(n,n,val,weight);

}