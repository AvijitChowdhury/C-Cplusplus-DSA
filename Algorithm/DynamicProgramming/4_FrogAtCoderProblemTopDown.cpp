/*link:https://atcoder.jp/contests/dp/tasks/dp_a
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
100 points

Problem Statement
There are 
N stones, numbered 
1,2,…,N. For each 
i (
1≤i≤N), the height of Stone 
i is 
h 
i
​
 .

There is a frog who is initially on Stone 
1. He will repeat the following action some number of times to reach Stone 
N:

If the frog is currently on Stone 
i, jump to Stone 
i+1 or Stone 
i+2. Here, a cost of 
∣h 
i
​
 −h 
j
​
 ∣ is incurred, where 
j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone 
N.

Constraints
All values in input are integers.
2≤N≤10 
5
 
1≤h 
i
​
 ≤10 
4
 
Input
Input is given from Standard Input in the following format:

N
h 
1
​
  
h 
2
​
  
… 
h 
N
​
 
Output
Print the minimum possible total cost incurred.

Sample Input 1
Copy
4
10 30 40 20
Sample Output 1
Copy
30
If we follow the path 
1 → 
2 → 
4, the total cost incurred would be 
∣10−30∣+∣30−20∣=30.

Sample Input 2
Copy
2
10 10
Sample Output 2
Copy
0
If we follow the path 
1 → 
2, the total cost incurred would be 
∣10−10∣=0.

Sample Input 3
Copy
6
30 10 60 10 60 50
Sample Output 3
Copy
40
If we follow the path 
1 → 
3 → 
5 → 
6, the total cost incurred would be 
∣30−60∣+∣60−60∣+∣60−50∣=40.


 */

#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e5 + 10;
vector<int> dp(N, -1);
vector<int> a(N);

int frog(int n)
{
    //base case
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return dp[2];
    }
    //memoization
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int x = frog(n - 1) + abs(a[n - 1] - a[n]);
    int y = frog(n - 2) + abs(a[n - 2] - a[n]);
    dp[n] = min(x, y);

    return dp[n];
}
int32_t main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = abs(a[2] - a[1]);
    frog(n);

    if (dp[n] == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << dp[n] << endl;
    }
    return 0;
}