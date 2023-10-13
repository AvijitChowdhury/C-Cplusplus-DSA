//problemlink: https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/A
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
int add(int *x,int *y){
    return (long long)(*x+*y);
}
int main(){
int x,y;
scanf("%lld %lld",&x,&y);
printf("%lld",add(&x,&y));
return 0;
}