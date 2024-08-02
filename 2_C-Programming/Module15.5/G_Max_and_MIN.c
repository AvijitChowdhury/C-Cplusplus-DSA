//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/G
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long

int func(int *a,int n){
int mn=100005;
int mx=0;
for(int i=0;i<n;i++){
    if(a[i]>mx){mx=a[i];}
    if(a[i]<mn){mn=a[i];}
    
}
printf("%lld %lld",mn,mx);
}
int main(){
    int n;
    scanf("%lld",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    func(a,n);


return 0;
}
