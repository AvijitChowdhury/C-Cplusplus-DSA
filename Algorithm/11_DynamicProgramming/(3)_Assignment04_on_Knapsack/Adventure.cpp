/*link:https://www.hackerrank.com/contests/assignment-04-a-introduction-to-algorithms-a-batch-03-1/challenges/adventure-1
Once upon a time, there was a treasure hunter who ventured into an ancient temple in search of a valuable artifact. The temple was filled with traps and obstacles, and the treasure hunter had to carry all of his equipment with him.

The treasure hunter had a backpack with a limited weight capacity, and he could only carry a certain amount of equipment with him. Each piece of equipment had its own weight and value, and the treasure hunter needed to choose which items to bring to maximize the total value while keeping the total weight under the limit.

Help the treasure hunter to choose which items to bring in his backpack to maximize their total value while keeping the total weight of his backpack under a certain limit. Each item can only be included once.

Input Format

First line will contain , the number of test cases.
The first line of each test case will contain (Number of items) and (Total weight of backpack).
Second line of each test case will contain an array  containing the weights of all items.
Third line of each test case will contain an array  containting the values of all items.
Constraints

; Here 
; Here 
Output Format

Output the maximum total value you can obtain in the backpack for each test case.
Sample Input 0

2
4 7
2 3 4 5
4 7 6 5
4 17
10 1 6 9
6 10 10 8
Sample Output 0

13
28
Explanation 0

In the first test case case, he can take 2nd and 3rd item which total weight is 3+4=7 and total value is 7+6=13 and its the maximum value possible.*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int dp[N][N];

//time complexity: O(n*w)
int knapsack(vector<int>& value, vector<int>& weight, int n, int w) {
    if (n == 0 || w == 0) {
        return 0;
    }
    if (dp[n][w] != -1) {
        return dp[n][w];
    }

    if (weight[n - 1] <= w) {
        int left = value[n - 1] + knapsack(value, weight, n - 1, w - weight[n - 1]);
        int right = knapsack(value, weight, n - 1, w);
        return dp[n][w]= max(left, right);
    } else {
        return dp[n][w]= knapsack(value, weight, n - 1, w);
    }
    
}
void code(){
//n measns number of items or index of items
    int n;
    cin >> n;
    int w;
    cin >> w;
    vector<int> value(n);
    vector<int> weight(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }
    
    
    memset(dp, -1, sizeof(dp)); // Initialize dp array
    cout << knapsack(value, weight, n, w)<<endl;
}

int32_t main() {
    int t=1;
    cin>>t;
    while(t--){
        code();
    }
    
}
