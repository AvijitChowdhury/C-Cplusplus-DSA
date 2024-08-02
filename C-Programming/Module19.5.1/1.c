//link: https://www.hackerrank.com/contests/final-exam-a-introduction-to-c-programming-a-batch-03/challenges/missing-number-31-1
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void solve(){
int s,a,b,c;
scanf("%lld %lld %lld %lld",&s,&a,&b,&c);
    int sum= a+b+c;
    int ans = s-sum;
    printf("%lld\n",ans);
}
int main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        solve();
    }
    return 0;
}