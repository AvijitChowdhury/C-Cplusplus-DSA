//ॐ भूर् भुवः स्वः।तत् सवितुर्वरेण्यं । भर्गो देवस्य धीमहि।धियो यो नः प्रचोदयात्|//
// Jay shree krishna
// Avijit Chowdhury(CUET)
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
typedef long long ll;
typedef long double ld;
double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
#define fr(a, b, c) for (ll(a) = (b); (a) < (c); ++(a))
#define frr(a, b, c) for (ll(a) = (b); (a) >= (c); --(a))
#define reset(a, b) memset(a, b, sizeof(a))
#define tr true
#define fl false
#define mod 1000000007
#define endl "\n"
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
#define allA(arr, sz) arr, arr + sz
#define srt(v) sort(all(v))
#define rvrs(v) reverse(all(v))
#define srta(arr, sz) sort(allA(arr, sz))
#define rvrsA(arr, sz) reverse(ALLA(arr, sz))
#define prmt next_permutation
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x, y) fixed << setprecision(y) << x
ll div_up(ll a, ll b) {
  return a / b + ((a ^ b) > 0 && a % b);
} // divide a by b rounded up
ll div_down(ll a, ll b) {
  return a / b - ((a ^ b) < 0 && a % b);
} // divide a by b rounded down
#define stoin(x) x - '0'
#define intost(x) x + '0'
#define w(x)                                                                   \
  ll x;                                                                        \
  cin >> x;                                                                    \
  while (x--)
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define fast                                                                   \
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
void solve() {
int index;
   string my_str ;
   string sub_str ;
   cin>>my_str>>sub_str;
   //replace all Hello with welcome
   while((index = my_str.find(sub_str)) != string::npos) {    //for each location where Hello is found
      my_str.replace(index, sub_str.length(),"$"); //remove and replace from that position
   }
   cout<<my_str<<endl;
}
int32_t main() {
  fast w(x) { solve(); }
  return 0;
}