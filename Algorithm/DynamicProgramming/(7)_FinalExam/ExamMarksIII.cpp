/*link: https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-03/challenges/exam-marks-iii
Problem Statement

Zarif has received  marks in his final term exam out of . However, he wishes to obtain a perfect score of  marks just once in his life. His wish was granted by a fairy who provided him with a list of  marks to choose from. Zarif needs to select any number of marks from that list, and he can choose each mark any number of times he wants. Whenever he chooses a mark, it is counted as a step, and this time the fairy told him to choose in the minimum steps possible.

Can you tell what will be the minimum steps Zarif will need to fulfill his dream. If it is not possible then print .

Input Format

First line will contain , the number of test cases.
First line of each test case will contain  and .
Second line of each test case will contain a list  of  marks.
Constraints

; 
Output Format

Output minimum number of steps needed if he can obtain perfect score of ,  otherwise.
Sample Input 0

5
5 1000
1 2 3 4 5
5 999
2 3 4 5 6
2 900
30 40
3 904
2 6 5
2 904
2 5
Sample Output 0

0
-1
3
16
21*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int unboundedKnapsack(int n, int s,int weight[]){
    int dp[n+1][s+1];
    dp[0][0]=0;
    for(int i=1;i<=s;i++){
        dp[0][i]=INT_MAX-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(weight[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-weight[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
  
    return dp[n][s];
}
void code(){
    int n,sum;
    cin>>n>>sum;
    int val[n],weight[n];
    
    for(int i=0;i<n;i++){
        cin>>weight[i];
        
    }
    if(sum==1000){
        cout<<0<<endl;
        return;
    }
    if(unboundedKnapsack(n,abs(1000-sum),weight)==INT_MAX-1){
        cout<<-1<<endl;
        }
        else{
        cout<<unboundedKnapsack(n,abs(1000-sum),weight)<<endl;
        } 
}
int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        code();
    }
}