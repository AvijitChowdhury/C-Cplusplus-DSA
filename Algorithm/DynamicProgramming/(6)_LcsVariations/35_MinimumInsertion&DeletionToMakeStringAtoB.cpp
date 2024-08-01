/*
input:
heat 
tea

deletion: 2
insertion: 1*/
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
    string s1,s2;
    cin>>s1>>s2;
    int a = s1.size();
    int b=s2.size();
    int lcs=lcsBottomUP(s1,s1.size(),s2,s2.size());
    cout<<"Deletion: "<<a-lcs<<endl;
    cout<<"Insertion: "<<b-lcs<<endl;
    //scs=totalsize - lcs
    //deletion = a-lcs
    //insertion = b- lcs

}