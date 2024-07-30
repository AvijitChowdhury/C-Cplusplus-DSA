/*
INput:
4
1 2 4 6
7
OUtPut:
YES
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10;
int n,sum;
bool SubsetSum2(vector<int>&a,int sum,int index){
    bool dp[index+1][sum+1];
    dp[0][0]=1;
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=index;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=index;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
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
    if(SubsetSum2(a,sum,n)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}
