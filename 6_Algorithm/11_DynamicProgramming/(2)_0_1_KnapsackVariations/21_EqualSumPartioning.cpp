#include<bits/stdc++.h>
using namespace std;
int n;
int sum=0;
bool EqualSumPartioning(vector<int>&a,int sum,int index){
    bool dp[index+1][sum+1];
    for(int i=0;i<=index;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=index;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]||dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[index][sum];
}


int32_t main(){
    
    cin>>n;
    vector<int> a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%2!=0){
        cout<<"NO"<<endl;
        return 0;
    }
    sum=sum/2;
    if(EqualSumPartioning(a,sum,n)){
        cout<<"YES"<<endl;
    }
    
}