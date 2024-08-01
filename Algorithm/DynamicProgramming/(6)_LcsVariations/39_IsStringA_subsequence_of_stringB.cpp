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

/*
another approach using two pointers
time complexity O(n+m)
*/
bool check(string a,string b){
    int n=a.size();
    int m = b.size();
    int x=0;bool ans = false;
    for(char c:b){
        if(c==a[x]){
            x++;
        }else if(x==a.size()){
            ans= true;
            break;
        }
    }
    return ans;
    }
int32_t main(){
    string a;
    cin>>a;
    string b;
    cin>>b;
    int lcs = lcsBottomUP(a,a.size(),b,b.size());
    if(lcs==a.size()){
        cout<<"YES";}
    else{
        cout<<"NO";
    }

}
// Time Complexity: O(n*m)
