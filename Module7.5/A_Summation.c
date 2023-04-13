//problem link:https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/A
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
long long int x = 1e5+10;
long long int a[100000];
int main(){
    long long int n;
    scanf("%lld",&n);
    
    long long int sum=0;

    for(long long int i=0 ;i<n;i++){scanf("%lld",&a[i]);}
    for(long long int i=0 ;i<n;i++){sum+=a[i];}
    if(sum<0){
        sum*=(long long int)(-1);
        printf("%lld",sum);
    }else{
        printf("%lld",sum);
    }
return 0;
}