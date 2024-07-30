/*
linK:https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03-1/challenges/exam-marks
Zarif has received  marks in his final term exam out of . However, he wishes to obtain a perfect score of  marks just once in his life. His wish was granted by a fairy who provided him with a list of  marks to choose from. Zarif needs to select any number of marks from that list, but he can choose each mark only once.

Can you tell if he can select marks from this list in such a way that his total marks add up to ?

Input Format

First line will contain , the number of test cases.
First line of each test case will contain  and .
Second line of each test case will contain a list  of  marks.
Constraints

; 
Output Format

Output "YES" if he can obtain perfect score of , "NO" otherwise.
Sample Input 0

3
5 1000
1 2 3 4 5
5 999
2 3 4 5 6
6 900
10 20 30 40 50 60
Sample Output 0

YES
NO
YES*/

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
// int dp[N][N];

bool SubsetSum2(vector<int>&a,int sum,int index){
    bool dp[index+1][sum+1];
    dp[0][0]=1;
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
    }
    
    for(int i=1;i<=index;i++){
        for(int j=0;j<=sum;j++){
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
    int n,target;
    cin>>n>>target;  
    int sum=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];   
    }
    if(SubsetSum2(a,abs(target-1000),n)){
        cout<<"YES"<<endl;}
        else{
            cout<<"NO"<<endl;
        }

}
int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        code();
    }
}
