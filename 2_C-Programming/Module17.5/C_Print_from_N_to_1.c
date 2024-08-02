//link: //link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/C
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void func(int n){
    if(n==0){
        return;
    }
    if(n==1){
        printf("%lld",n);
    }else{
    printf("%lld ",n);
    }func(n-1);
    
}
int main(){
int n;
scanf("%lld",&n);
func(n);
return 0;
}