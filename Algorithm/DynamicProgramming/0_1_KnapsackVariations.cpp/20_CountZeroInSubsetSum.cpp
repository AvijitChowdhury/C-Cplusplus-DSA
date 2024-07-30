/*
INput:
4
1 2 4 6
7
OUtPut:
YES
dp table:
1 0 0 0 0 0 0 0 
2 0 0 0 0 0 0 0 
4 0 0 0 0 0 0 0 
8 0 0 0 0 0 0 0 
16 0 0 0 0 0 0 0 
16 0 0 0 0 0 0 16


*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10;
int n,sum;
int CountSubsetSum(vector<int>&a,int sum,int index){
    int dp[index+1][sum+1];
    dp[0][0]=1;
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=index;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=index;i++){
        for(int j=0;j<=sum;j++){//for calculating number of ways of subset sum 
        //we are starting from 0 because we are calculating number of ways of subset sum
        //if we start from 1 then we will get number of subset sum
        //if we start from 0 then we will get number of ways of subset sum
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=index;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[index][sum];
}


int32_t main(){
    
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cin>>sum;
    //memset(dp,-1,sizeof(dp));
    cout<<"Number of ways of subset sum: "<<CountSubsetSum(a,sum,n)<<endl;
    
}
