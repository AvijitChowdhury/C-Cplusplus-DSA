/*link: https://leetcode.com/problems/min-cost-climbing-stairs/description/
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

 

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.
Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
 

Constraints:

2 <= cost.length <= 1000
0 <= cost[i] <= 999*/
class Solution {
public:
    int dp[1000];
    int minCost(vector<int>&cost,int n){
        int sz = cost.size();
        if(n<0){return 0;}
        if(dp[n]!=-1){return dp[n];}
        int op1 = cost[n]+minCost(cost,n-2);
        int op2 =cost[n]+ minCost(cost,n-1);
        return dp[n]=min(op1,op2);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        memset(dp,-1,sizeof(dp));
        return min(minCost(cost,n-1),minCost(cost,n-2));
        
    }
};