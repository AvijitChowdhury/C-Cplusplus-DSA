// link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/L
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
int func(int a[],int i,int n){
    if(i==n){
        return 0;
    }
    
    int cnt=func(a,i+1,n);
    cnt+=a[i];
    return cnt;
    
}
int main(){
int n;
scanf("%lld",&n);
int a[n];
for(int i=0;i<n;i++){scanf("%lld",&a[i]);}

int cnt=func(a,0,n);
printf("%lld",cnt);
return 0;
}