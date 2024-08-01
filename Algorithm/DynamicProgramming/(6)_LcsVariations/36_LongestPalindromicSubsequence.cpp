/*
input:
mkabcdabm
ans : 5

abcad
3*/
#include<bits/stdc++.h>
using namespace std;

int lcsBottomUP(string s1,int n,string s2,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];

}


int32_t main(){
    string s;
    cin>>s;
    int sz= s.size();
    //scs=totalsize - lcs
    string s1=s;
    reverse(s.begin(),s.end());
    cout<<lcsBottomUP(s1,s1.size(),s,s.size());

}