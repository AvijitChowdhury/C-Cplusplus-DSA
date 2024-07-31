/*
Input:
4 6
5 3 2 4
4 1 3 2*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int dp[1001][1001]={-1};
int unboundedKnapsack(int n, int s, int val[], int weight[]){
    if(n==0||s==0){
        return 0;
    }
    if(dp[n][s]!=-1){
        return dp[n][s];
    }
    if(weight[n-1]<=s){
        int op1=val[n-1]+unboundedKnapsack(n,s-weight[n-1],val,weight);
        int op2 = unboundedKnapsack(n-1,s,val,weight);
        return dp[n][s]=max(op1,op2);
    }else{
        return dp[n][s]=unboundedKnapsack(n-1,s,val,weight);
    }
}
int32_t main(){
    int n,s;
    cin>>n>>s;
    int val[n],weight[n];
    fill(dp,dp+n,-1);
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<unboundedKnapsack(n,s,val,weight);

}