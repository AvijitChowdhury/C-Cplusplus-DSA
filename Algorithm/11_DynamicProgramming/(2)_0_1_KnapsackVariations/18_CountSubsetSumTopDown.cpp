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
int dp[N][N];
int n,sum;

int CountSubsetSum(vector<int>&a,int sum,int index){
    
    if(index==0){
        if(sum==0){
            return 1;
        }else{
            return 0;
        }
    }
    else if (dp[index][sum]!=-1){
        return dp[index][sum];
    }
    if(a[index-1]<=sum){
        bool left = CountSubsetSum(a,sum-a[index-1],index-1);
        bool right = CountSubsetSum(a,sum,index-1);
        return dp[index][sum]= left+right;}
    else{
        return dp[index][sum]=CountSubsetSum(a,sum,index-1);
    }


}


int32_t main(){
    
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cin>>sum;
    memset(dp,-1,sizeof(dp));
    // if(SubsetSum(a,0,0)){
    //     cout<<"YES"<<endl;
    // }else{
    //     cout<<"NO"<<endl;
    // }
    cout<<"Number of ways of subset sum: "<<CountSubsetSum(a,sum,n)<<endl;
}
