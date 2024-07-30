/*
4
1 1 2 3
target sum = 1
one way: +1 -1 -2 +3
second way: +1 +1 +2 -3
third way: -1 +1 -2 +3
ans is 3
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,index;
int sum=0;
int dp[N][N];
int CountSubsetsumWithGivenDiff(vector<int>&a,int sum,int index){
    
    dp[0][0] = true;
    for(int i=1;i<=sum;i++){
        dp[0][i]=false;
    }
   
    for(int i=1;i<=index;i++){
        for(int j=0;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
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
    //as it is target sum so diff is target
    // int diff;cin>>diff;
    int target;cin>>target;
    /*
    s1-s2 = diff------->1
    s1+s2 = sum------->2
    --------------------
    2*s1  = (diff+sum)
    so, s1 = (diff+sum)/2
    */
    int s1=(target+sum)/2;
    cout<<CountSubsetsumWithGivenDiff(a,s1,n)<<endl;

}