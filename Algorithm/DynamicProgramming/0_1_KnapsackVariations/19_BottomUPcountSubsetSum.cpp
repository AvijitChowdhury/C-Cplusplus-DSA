/* link: https://www.naukri.com/code360/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&count=25&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM&page=1
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.



Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.



Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.



Example:
Input: 'arr' = [1, 1, 4, 5]

Output: 3

Explanation: The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
4 5
1 4 4 5


Sample Output 1 :
 3


Explanation For Sample Output 1:
The possible ways are:
[1, 4]
[1, 4]
[5]
Hence the output will be 3. Please note that both 1 present in 'arr' are treated differently.


Sample Input 2 :
3 2
1 1 1


Sample Output 2 :
3


Explanation For Sample Output 1:
There are three 1 present in the array. Answer is the number of ways to choose any two of them.


Sample Input 3 :
3 40
2 34 5


Sample Output 3 :
0


Expected time complexity :
The expected time complexity is O('n' * 'k').


Constraints:
1 <= 'n' <= 100
0 <= 'arr[i]' <= 1000
1 <= 'k' <= 1000

Time limit: 1 sec*/
/*
INput:
4
1 2 4 6
7
OUtPut:
YES
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10;
const int mod= 1e9+7;
int n,sum;
int CountSubsetSum(vector<int>&a,int sum,int index){
    int dp[index+1][sum+1];
    dp[0][0]=1;
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=index;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=index;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[index][sum]%=mod;
}


int32_t main(){
    
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    cin>>sum;
    //memset(dp,-1,sizeof(dp));
    cout<<"Number of ways of subset sum: "<<CountSubsetSum(a,sum,n)<<endl;
    
}
