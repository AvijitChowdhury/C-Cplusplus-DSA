//link: https://codeforces.com/contest/1991/problem/B

#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
int n, b[MAX_N], a[MAX_N];

#define int long long
void code(){
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
        cin >> b[i];
    b[0] = b[n] = 0;
    for (int i = 1; i <= n; i++)
        a[i] = b[i - 1] | b[i];
    bool valid = true;
    for (int i = 1; i < n; i++)
        if ((a[i] & a[i + 1]) != b[i]) {
            valid = false;
            break;
        }
    if (valid) {
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    } else
        cout << -1 << endl;
    
}
int32_t main(){
    int t;
    cin >> t; // Initialize 't' with a value
    while(t--){
        code();
    }

}
