/*link:https://www.hackerrank.com/contests/final-exam-a-introduction-to-algorithms-a-batch-03/challenges/make-palindrome-5-2
Meet Mina, who's really into playing with words, especially those cool things called palindromes. Palindromes are like magic words that read the same backward and forward. Now, Mina's got this word in her head, but she's not sure how to make it a palindrome.

Here's the challenge: Mina can add letters to her word, but each letter she adds costs her  minute of time. Mina wants to be smart about it and not waste too much time. That's where you come in!

Your job is to help Mina figure out the quickest way to turn her word into a palindrome. Imagine the clock is ticking, and Mina is waiting for your super-smart advice. Let's make this word magic happen fast and fun!

Input Format

First line will contain , the number of test cases.
Each line of the test case will contain the string .
Constraints

; Here  means the length of . The string will contain only English alphabets and won't contain any spaces.
Output Format

Output the minimum time needed to make the string palindrome.
Sample Input 0

5
madam
mcadam
madcam
mcaedam
macdarm
Sample Output 0

0
1
1
2
2
*/
#include<bits/stdc++.h>
using namespace std;

int lcsBottomUP(string s1,int n,string s2,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];

}

void code(){
string s;
    cin>>s;
    int sz= s.size();
    //scs=totalsize - lcs
    string s1=s;
    reverse(s.begin(),s.end());
    int lps=lcsBottomUP(s1,s1.size(),s,s.size());
    //minimum deletion or insertion
    //ans = s.size()-lps
    cout<<sz-lps<<endl;;
}
int32_t main(){
    int t=1;cin>>t;
    while(t--){
        code();
    }
}