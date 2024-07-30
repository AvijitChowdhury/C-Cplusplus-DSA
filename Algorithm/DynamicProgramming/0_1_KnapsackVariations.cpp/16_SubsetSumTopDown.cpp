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
bool SubsetSum(vector<int>&a,int value,int index){
    if(index==n+1){
        if(value==sum){
            return true;
        }else{
            return false;
        }
    }
    if(dp[index][value]!=-1){
        return dp[index][value];
    }
    int left= SubsetSum(a,value+a[index],index+1);
    int right = SubsetSum(a,value,index+1);
    return dp[index][value]=left||right;  
}
bool SubsetSum2(vector<int>&a,int sum,int index){
    
    if(index<0){
        if(sum==0){
            return true;
        }else{
            return false;
        }
    }
    else if (dp[index][sum]!=-1){
        return dp[index][sum];
    }
    if(a[index-1]<=sum){
        bool left = SubsetSum2(a,sum-a[index-1],index-1);
        bool right = SubsetSum2(a,sum,index-1);
        return dp[index][sum]= left||right;}
    else{
        return dp[index][sum]=SubsetSum2(a,sum,index-1);
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
    if(SubsetSum2(a,sum,n)){
        cout<<"YES"<<endl;}
    else{
        cout<<"NO"<<endl;
    }
}
