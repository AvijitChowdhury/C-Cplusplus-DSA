/*link:https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-03/challenges/exam-marks-iv
Problem Statement

Zarif has received M marks in his final term exam out of 1000. However, he wishes to obtain a perfect score of 1000 marks just once in his life. His wish was granted by a fairy who provided him with a list of N marks to choose from. Zarif needs to select any number of marks from that list, and he can choose each mark any number of times he wants. Fairy asked him how many ways he can do this. She wanted Zarif to answer the maximum ways he can choose those marks.

Can you tell what will be the maximum number of ways to choose those marks to fulfill his dream?

Note: As the answer can be very long, whenever the answer gets bigger than 1e9+7, mod it with 1e9+7.

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N and M.
Second line of each test case will contain a list A of N marks.
Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= M <= 1000
1 <= A[i] <= 100; 0 <= i < N
Output Format

Output the maximum number of ways.
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

1
0
1
92
10
Sample Input 1

2
30 0
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
20 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
Sample Output 1

158493259
888281419*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int
int mod = 1e9+7;

int unboundedKnapsack(int n, int s,int w[]){
    int dp[n + 1][s + 1];
    dp[0][0] = 1;

    for (int i = 1; i <= s; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (w[i - 1] <= j) {
                dp[i][j] = dp[i][j - w[i - 1]]%mod + dp[i - 1][j]%mod;
            } else {
                dp[i][j] = dp[i - 1][j]%mod;
            }
        }
    }
    
  
    return dp[n][s]%=mod;
}
void code(){
    int n,sum;
    cin>>n>>sum;
    int val[n],weight[n];
    
    for(int i=0;i<n;i++){
        cin>>weight[i];
        
    }
    if(sum==1000){
        cout<<1<<endl;
        return;
    }
    cout<<unboundedKnapsack(n,abs(1000-sum),weight)<<endl;
       // } 
}
int32_t main(){
    int t=1;
    cin>>t;
    while(t--){
        code();
    }
}