/*
Link:https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/V
Given two numbers N
 ,X
 and an array A
 of N
 numbers. Determine if there is a way to put '+' or '-' signs between every two numbers in the array A
 in order to make an expression that is equal to X
.

Note: Solve this problem using recursion.

Input
First line contains two numbers N
 and X
 (1≤N≤20,−109≤X≤109)
.

Second line contains N
 distinct numbers A1,A2,....AN
 (1≤Ai≤105)
.

Output
Print "YES" if you can put '+' or '-' signs between every two number to create an expression that is equal to X
 otherwise, print "NO".

Examples
InputCopy
5 5
1 2 3 4 5
OutputCopy
YES
InputCopy
5 2
1 2 3 4 5
OutputCopy
NO
Note
In the first example: 1 - 2 - 3 + 4 + 5 = 5*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX_N = 25;


int dp[MAX_N][MAX_N]; // Assuming maximum sum is 1000
int item, result;
vector<int> v(MAX_N);
int cnt=0;
bool check(int n, int value) {
    
    //cnt++;
    //cout<<n<<" "<<value<<endl;
    if(n==item){
        if(value==result){
            return true;
        }else{
            return false;
        }

    }
        // Base cases: no elements left or target is negative

    //if (dp[n][value] != -1) return dp[n][value]; // Check memoization

    bool left = check(n + 1, value - v[n]); // Try subtracting the last element
    bool right = check(n + 1, value +v[n]); // Try adding the last element

    return left || right; // Store result in dp and return
}

int32_t main() {
    cin >> item >> result;
    for (int i = 0; i < item; i++) {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    if(check(v[0], 1)){
        cout<<"YES"<<endl;}
        else{
            cout<<"NO"<<endl;
        }
    //cout<<cnt<<endl;
    return 0;
}
