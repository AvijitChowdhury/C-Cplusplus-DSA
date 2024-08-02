/*
input:
peak
eke
ans :5

ckkgcd
kxgxcyd
0 0 0 0 0 0 0 0 
0 0 0 0 0 1 1 1 
0 1 1 1 1 1 1 1 
0 1 1 1 1 1 1 1 
0 1 1 2 2 2 2 2 
0 1 1 2 2 3 3 3 
0 1 1 2 2 3 3 4 

length of shortest common supersequence is : 9
ckkxgxcyd*/
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
    int i=n,j=m;
    string ans;
    while(i!=0&&j!=0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            ans+=s1[i-1];
            i--;
        }else{
            //ans+=s1[i-1];
            ans+=s2[j-1];
            j--;
        }
    }
    while(i!=0){
        ans+=s1[i-1];
        i--;
    }
    while(j!=0){
        ans+=s2[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<"length of shortest common supersequence is : "<<ans.size()<<endl;    

    cout<<ans<<endl;

}


int32_t main(){
    string s1,s2;
    cin>>s1>>s2;
    int totalsize=s1.size()+s2.size();
    scsBottomUP(s1,s1.size(),s2,s2.size());
    //scs=totalsize - lcs

}