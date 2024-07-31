/*
link: https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference


Example 1:

Input: N = 4, arr[] = {1, 6, 11, 5} 
Output: 1
Explanation: 
Subset1 = {1, 5, 6}, sum of Subset1 = 12 
Subset2 = {11}, sum of Subset2 = 11   
Example 2:
Input: N = 2, arr[] = {1, 4}
Output: 3
Explanation: 
Subset1 = {1}, sum of Subset1 = 1
Subset2 = {4}, sum of Subset2 = 4

Your Task:  
You don't need to read input or print anything. Complete the function minDifference() which takes N and array arr as input parameters and returns the integer value


Expected Time Complexity: O(N*|sum of array elements|)
Expected Auxiliary Space: O(N*|sum of array elements|)


Constraints:
1 ≤ N*|sum of array elements| ≤ 106
0 < arr[i] <= 105*/
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
int MinimumSubsetSumDifference(vector<int>&a,int sum,int index){
    
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