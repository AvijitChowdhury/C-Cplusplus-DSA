/*link:https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-03/challenges/exam-marks-2
Zarif has received  marks in his final term exam out of . However, he wishes to obtain a perfect score of  marks just once in his life. His wish was granted by a fairy who provided him with a list of  marks to choose from. Zarif needs to select any number of marks from that list, and he can choose each mark any number of times he wants.

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
2 900
30 40
Sample Output 0

YES
NO
YES*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int unboundedKnapsack(int n, int s,int weight[]){
    int dp[n+1][s+1];
    dp[0][0]=1;
    for(int i=1;i<=s;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(weight[i-1]<=j){
                dp[i][j]=dp[i][j-weight[i-1]]||dp[i-1][j];
            }else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=s;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
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
        cout<<"YES"<<endl;
        return;
    }
    
    if(unboundedKnapsack(n,abs(1000-sum),weight)){
        cout<<"YES"<<endl;
    }else{
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