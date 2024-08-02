//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/F
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

long long int a[100000];
int main(){
long long int n;
scanf("%lld",&n);
for(long long int i= 0;i<n;i++){scanf("%lld",&a[i]);}
for(long long int i=n-1 ;i>=0;i--){
    printf("%lld ",a[i]);
   
}


return 0;
}