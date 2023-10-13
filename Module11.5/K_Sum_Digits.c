// prblem link; https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/K
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define int long long
#define stoin(x) x - '0'
int main()
{
    long long x;
    scanf("%lld", &x);
    char s[x];
    int sum=0;

    scanf("%s", &s);
    for(int i=0;i<strlen(s);i++){
        sum+=(long long )(stoin(s[i]));
    }
    printf("%lld",sum);
    

    return 0;
}