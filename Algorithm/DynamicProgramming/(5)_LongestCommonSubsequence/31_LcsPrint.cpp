/*
abdef
adegf
output:feda

Testcase2:
abd
gbad
output:ad
dp table:
0 0 0 0 0 
0 0 0 1 1 
0 0 1 1 1 
0 0 1 1 2

TestCase3:
abccdgceg
azbaccgef
output:abccge
dp table:
0 0 0 0 0 0 0 0 0 0 
0 1 1 1 1 1 1 1 1 1 
0 1 1 2 2 2 2 2 2 2 
0 1 1 2 2 3 3 3 3 3 
0 1 1 2 2 3 4 4 4 4 
0 1 1 2 2 3 4 4 4 4 
0 1 1 2 2 3 4 5 5 5 
0 1 1 2 2 3 4 5 5 5 
0 1 1 2 2 3 4 5 6 6 
0 1 1 2 2 3 4 5 6 6 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

string LcsBottomUp(string s1,int n,string s2,int m){    
    
    int dp[n+1][m+1];
  
    //base case:
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    string s="";
    int i=n,j=m;
    while(i!=0&&j!=0){
    //for(;i>0,j>0;){ //alternative
            if(s1[i-1]==s2[j-1]){
                s.push_back(s1[i-1]);
                i--;j--;
            }else{
                if(dp[i][j-1]>dp[i-1][j]){
                    j--;
                }else{
                    i--;
                }
            }
        }
    reverse(s.begin(),s.end());   
    return s;

}


int32_t main(){
    string s1,s2;
    cin>>s1>>s2;
    
    cout<<LcsBottomUp(s1,s1.size(),s2,s2.size())<<endl;
}