//problem linK: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/V
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long 
int cnt[100000]={0};
int main(){
    int n,m;
    scanf("%lld %lld",&n,&m);
    int a[n];
    
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=1;i<=m;i++){
        printf("%lld\n",cnt[i]);
    }

return 0;
}