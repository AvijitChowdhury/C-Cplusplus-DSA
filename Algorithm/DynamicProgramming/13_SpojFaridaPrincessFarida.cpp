/*link: https://www.spoj.com/problems/FARIDA/en/

Once upon time there was a cute princess called Farida living in a castle with her father, mother and uncle. On the way to the castle there lived many monsters. Each one of them had some gold coins. Although they are monsters they will not hurt. Instead they will give you the gold coins, but if and only if you didn't take any coins from the monster directly before the current one. To marry princess Farida you have to pass all the monsters and collect as many coins as possible. Given the number of gold coins each monster has, calculate the maximum number of coins you can collect on your way to the castle.

Input
The first line of input contains the number of test cases. Each test case starts with a number N, the number of monsters, 0 <= N <= 10^4. The next line will have N numbers, number of coins each monster has, 0 <= The number of coins with each monster <= 10^9. Monsters described in the order they are encountered on the way to the castle.

Output
For each test case print “Case C: X” without quotes. C is the case number, starting with 1. X is the maximum number of coins you can collect.

Example
Input:
2
5
1 2 3 4 5
1
10

Output:
Case 1: 9
Case 2: 10*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int 
const int N = 1e4+10;
int dp[N]={-1};
int n;

int maxCoin(vector<int>& coins, int i){
    if(i>=n){return 0;}
    else if(dp[i]!=-1){return dp[i];}
    
        int op1 = coins[i]+maxCoin(coins,i+2);//pick the coin and move to next to next
        int op2 = maxCoin(coins,i+1);//not pick the coin and move to next
        return dp[i]= max(op1,op2);
    // } //either take the coin or not take the coin and move to next


}
void code(int t){

cin>>n;
vector<int> coins(n);
for(int i=0;i<n;i++){
    cin>>coins[i];
}
if(n==0){
    cout<<"Case 1: 0"<<endl;
    return;
}   
    fill(dp,dp+n,-1);
    int ans=maxCoin(coins,0);
    cout<<"Case "<<t<<": "<<ans<<endl;

}

int32_t main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        code(i);}
}
