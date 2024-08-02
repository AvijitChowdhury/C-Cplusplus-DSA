/*link: https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Example 1:

Input: 
N = 2
W = 3
val = {1, 1}
wt = {2, 1}
Output: 
3
Explanation: 
1.Pick the 2nd element thrice.
2.Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1  = 3 which is <= 3.
Example 2:

Input: 
N = 4
W = 8
val[] = {6, 1, 7, 7}
wt[] = {1, 3, 4, 5}
Output: 
48
Explanation: 
The optimal choice is to pick the 1st element 8 times.
Your Task:
You do not need to read input or print anything. Your task is to complete the function knapSack() which takes the values N, W and the arrays val and wt as input parameters and returns the maximum possible value.

Expected Time Complexity: O(N*W)
Expected Auxiliary Space: O(W)

Constraints:
1 ≤ N, W ≤ 1000
1 ≤ val[i], wt[i] ≤ 100*/
/*
Input:
4 6
5 3 2 4
4 1 3 2
OUtput:18

3 5
5 3 2
4 5 3
output: 5*/
/*
dp table:
0 0 0 0 0 0 
0 0 0 0 5 5 
0 0 0 0 5 5 
0 0 0 2 5 5 */
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int unboundedKnapsack(int n, int s, int val[], int weight[]){
    int dp[n+1][s+1];
    for (int i = 0; i <= n; i++){ 
        for (int j = 0; j <= s; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(weight[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i][j-weight[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][s];
}
int32_t main(){
    int n,s;
    cin>>n>>s;
    int val[n],weight[n];
    
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    cout<<unboundedKnapsack(n,s,val,weight);

}