/*
input:
peak
eke
ans :5

ckkgcd
kxgxcyd
9*/
#include<bits/stdc++.h>
using namespace std;
int scsBottomUP(string s1,int n,string s2,int m){
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
    return n+m-dp[n][m];

}


int32_t main(){
    string s1,s2;
    cin>>s1>>s2;
    int totalsize=s1.size()+s2.size();
    cout<<scsBottomUP(s1,s1.size(),s2,s2.size());
    //scs=totalsize - lcs

}