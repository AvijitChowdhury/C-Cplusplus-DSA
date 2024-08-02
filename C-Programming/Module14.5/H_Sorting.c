//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/H
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
int main(){
    int n;
    scanf("%lld",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%lld ",a[i]);
    }

return 0;
}