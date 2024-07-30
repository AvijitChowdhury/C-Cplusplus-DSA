/*
4
1 1 2 3
diff = 1
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,index;
int sum=0;
bool dp[N][N];
bool MinimumSubsetSumDifference(vector<int>&a,int sum,int index){
    
    dp[0][0] = true;
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
    vector<int> v;
    for(int i=0;i<=index;i++){
        for(int j=0;j<=sum;j++){
            if(dp[i][j]){
            
                v.push_back(j);
            }
        }
    }
    int mn = INT_MAX;
    for(auto val:v){
        int s1 = val;
        int s2 = sum-val; 
        mn = min(mn,abs(s1-s2));
    }
    return mn;
}
int32_t main(){
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    cout<<MinimumSubsetSumDifference(a,sum,n)<<endl;

}