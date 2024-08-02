/*
There are a list of N values which were inserted into a stack and a list of M values which were inserted into a queue. After that the elements of the stack and queue are removed and put them into the list where the belong. You need to tell if both of the list are same or not after removing those elements from the stack and queue.

Note: You need to use STL Stack and Queue to solve this problem. You can't insert those values to anything else.

Input Format

First line will contain N and M.
Second line will contain list A with N values.
Third line will contain list B with M values.
Constraints

1 <= N, M <= 10^6
0 <= Values of list A and B <= 1000
Output Format

Output "YES" if they were same, otherwise "NO".
Sample Input 0

5 5
10 20 30 40 50
50 40 30 20 10
Sample Output 0

YES
Sample Input 1

4 4
10 20 30 40
10 20 30 40
Sample Output 1

NO
Sample Input 2

5 4
10 20 30 40 50
50 40 30 20
Sample Output 2

NO
Submissions: 673
Max Score: 20
Difficulty: Easy
Rate This Challenge:

    
More
There are a list of N values which were inserted into a stack and a list of M values which were inserted into a queue. After that the elements of the stack and queue are removed and put them into the list where the belong. You need to tell if both of the list are same or not after removing those elements from the stack and queue.

Note: You need to use STL Stack and Queue to solve this problem. You can't insert those values to anything else.

Input Format

First line will contain N and M.
Second line will contain list A with N values.
Third line will contain list B with M values.
Constraints

1 <= N, M <= 10^6
0 <= Values of list A and B <= 1000
Output Format

Output "YES" if they were same, otherwise "NO".
Sample Input 0

5 5
10 20 30 40 50
50 40 30 20 10
Sample Output 0

YES
Sample Input 1

4 4
10 20 30 40
10 20 30 40
Sample Output 1

NO
Sample Input 2

5 4
10 20 30 40 50
50 40 30 20
Sample Output 2

NO
Submissions: 673
Max Score: 20
Difficulty: Easy
Rate This Challenge:

    
More
*/
#include <bits/stdc++.h>
#include <stack>
#include <queue>
using namespace std;
void code(){
  int n, m;
  cin >> n >> m;
  if(n!=m){
      cout<<"NO";
      return;
  }

  stack<int> st;
  queue<int> qu;


  for (int i = 0; i < n; i++) {
    int data;
    cin >> data;
    st.push(data);
  }

  for (int i = 0; i < m; i++) {
    int data;
    cin >> data;
    qu.push(data);
  }

  bool same = true;

  for (int i = 0; i < n && i < m; i++) {
    if (st.top() != qu.front()) {
      same = false;
      break;
    }
    st.pop();
    qu.pop();
  }

  if (same) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

}
int main() {
  code();
  return 0;
}