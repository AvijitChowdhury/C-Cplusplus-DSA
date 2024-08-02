//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/M
#include<stdio.h>
#include<conio.h>

int main(){
    long long int n,mn=100000,mx=-100000,psmn,psmx;
    scanf("%lld",&n);
    long long int a[n+1];
    
    for(long long int i=0;i<n;i++){
        scanf("%lld",&a[i]);
        if(a[i]<mn){mn=a[i];psmn=i;}
        if(a[i]>mx){mx=a[i];psmx=i;}
    }
    long long int temp = a[psmn];
    a[psmn]=mx;
    a[psmx]=temp;
    for(long long int i=0;i<n;i++){
        printf("%lld ",a[i]);
    }
    

return 0;
}