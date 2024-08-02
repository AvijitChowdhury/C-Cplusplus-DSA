/*
aceghr
acaeghbr
output
dptable:
0 0 0 0 0 0 0 0 0 
0 1 0 1 0 0 0 0 0 
0 0 2 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 0 
0 0 0 0 0 2 0 0 0 
0 0 0 0 0 0 3 0 0 
0 0 0 0 0 0 0 0 1 
3
hge

*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int dp[1001][1001];
int LcsTopDown(string s1,int n,string s2,int m){
    //longest common substring
    //top down approach
    if(n==0||m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1]){
        return dp[n][m]=1+LcsTopDown(s1,n-1,s2,m-1);
    }else{
        return dp[n][m]=0;
    }
    
}
void LcsBottomUp(string s1,int n,string s2,int m){    
    
    int dp[n+1][m+1];
  
    //base case:
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=0;
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }
    int mx=0;
    int ci,cj;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(dp[i][j]>mx){
                mx=dp[i][j];
                ci=i;
                cj=j;
            }
        }
    }
    cout<<mx<<endl;
    string ans="";
    while(ci!=0&&cj!=0){
        if(s1[ci-1]==s2[cj-1]){
            ans+=s1[ci-1];
            ci--;
            cj--;
        }else{
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;


}


int32_t main(){
    string s1,s2;
    cin>>s1>>s2;
    memset(dp,-1,sizeof(dp));
    
    cout<<"topdown: "<<LcsTopDown(s1,s1.size(),s2,s2.size())<<endl;
    for(int i=0;i<=s1.size();i++){
        for(int j=0;j<=s2.size();j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    // LcsBottomUp(s1,s1.size(),s2,s2.size());
    LcsTopDown(s1,s1.size(),s2,s2.size());
}