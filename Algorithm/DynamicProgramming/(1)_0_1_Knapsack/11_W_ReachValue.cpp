/*link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/W*/
// There are N

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
int dp[N];
bool check(int value,int n){
    if(n==value){
        return true;
    }
    else if(n>value){
        return false;
    }else if(dp[n]!=-1){
        return dp[n];}
    else{

    return dp[n]=check(value,n*10)||check(value,n*20);
}
}


int32_t main(){
    int t;
    cin >> t; // Initialize 't' with a value
    while(t--){
        int n;
        cin>>n;
        // memset(dp,-1,sizeof(dp));
        fill(dp,dp+n,-1);
        if(check(n,1)){
            cout<<"YES"<<endl;
        }else{
        cout<<"NO"<<endl;
    }}
}
