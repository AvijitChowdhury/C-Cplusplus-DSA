/*
You will be given an array A of size N. You need to tell which value occurs the most and the count of that value.

Note: If there are multiple values with the highest count, then pick the maximum value as answer.

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain N.
Second line of each test case will contain the array A of size N.
Constraints

1 <= T <= 100
1 <= N <= 10^5
-10^9 <= A[i] <= 10^9
Output Format

Output the number that occurs the most, then the count of that number.
Sample Input 0

3
10
2 1 3 5 4 6 5 2 1 3
10
-5 -2 1 5 -5 4 -2 -1 -2 -1
5
-1000000000 -112101 10100101 1000000000 12345
Sample Output 0

5 2
-2 3
1000000000 1*/
#include<bits/stdc++.h>
using namespace std;
void code() {
    int n;
    cin >> n;
    vector<int> v;
    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        mp[x]++;
    }

    int maxCount = 0;
    int mostFrequent;
    bool first = true; 

    for (const auto& it : mp) {
        if (it.second > maxCount) {
            maxCount = it.second;
            mostFrequent = it.first;
        } else if (it.second == maxCount) {
            for (int i = 0; i < n; i++) {
                if (v[i] == mostFrequent) {
                    break;
                }
                if (v[i] == it.first) {
                    mostFrequent = it.first;
                    break;
                }
            }
        }
    }
    for(auto it:mp){
        if(it.second==maxCount && it.first>mostFrequent){
            mostFrequent=it.first;
        }
    
    }

    cout << mostFrequent << " " << maxCount << endl;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        code();
    }
}