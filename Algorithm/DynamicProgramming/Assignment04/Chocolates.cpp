/*
link:https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03-1/challenges/make-it-2
You will be given a positive integer . You will start from  and do some steps (possibly zero).

In each step you can choose one of the following:

Add  with the current value
Multiply by  with the current value
Can you tell if you can reach  by using any number of steps you want.

Input Format

First line will contain , the number of test cases.
In each test case you will be given .
Constraints

Output Format

Print "YES" if you can reach , "NO" otherwise.
Sample Input 0

5
1
3
5
15
16
Sample Output 0

YES
NO
YES
NO
YES*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int dp[N][N];
int n;
//time complexity: O(n*w)
bool ChocolatePartion(vector<int>&a,int sum,int index){
    // if(n<0){
    //     if(sum==0){
    //         return 1;
    //     }else{
    //         return 0;
    //     }
    // }
    // if(dp[n][sum]!=-1){
    //     return dp[n][sum];
    // }
    // return dp[n][sum]=ChocolatePartion(a,sum-a[n],n-1)||ChocolatePartion(a,sum,n-1);
    bool dp[index+1][sum+1];
    dp[0][0]=1;
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
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
void code(){
//n measns number of items or index of items
    cin>>n;
    vector<int>a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    
    if(sum%2!=0){
        cout<<"NO"<<endl;
        return;
    }
    sum=sum/2;
    memset(dp, -1, sizeof(dp)); // Initialize dp array
    if(ChocolatePartion(a,sum,n)){
        cout<<"YES"<<endl;}
        else{
            cout<<"NO"<<endl;
        }
}

int32_t main() {
    int t=1;
    cin>>t;
    while(t--){
        code();
    }   
}
