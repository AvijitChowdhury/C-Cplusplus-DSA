/*
string 1:abdrh
string 2:gabr
output:3
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int dp[1001][1001];
int LcsTopDown(string s1,int n,string s2,int m){    
    if(n==0||m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1]){
        return dp[n][m]=1+LcsTopDown(s1,n-1,s2,m-1);
    }

   return dp[n][m]= max(LcsTopDown(s1,n-1,s2,m),LcsTopDown(s1,n,s2,m-1));

}


int32_t main(){
    string s1,s2;
    cin>>s1>>s2;
    memset(dp,-1,sizeof(dp));
    cout<<LcsTopDown(s1,s1.size(),s2,s2.size())<<endl;
}