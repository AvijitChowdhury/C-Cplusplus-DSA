/*
link: https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03-1/challenges/make-it-2
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
const int N = 1e5 + 5;
int dp[N];
int target;
//time complexity: O(n*w)
bool Makeit(int n){
    if(n==target){
        return 1;
    }else if(n>target){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=Makeit(n+3)||Makeit(n*2);
}
void code(){
//n measns number of items or index of items
    cin>>target;
    
    
    memset(dp, -1, sizeof(dp)); // Initialize dp array
    if(Makeit(1)){
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
