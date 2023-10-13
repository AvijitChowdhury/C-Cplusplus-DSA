//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/P
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
int main(){
int n;
scanf("%lld",&n);
int s=n-1;
for(int i=n;i>=1;i--){
    for(int j=0;j<i;j++){
        printf("*");
    }
    printf("\n");
}
return 0;
}