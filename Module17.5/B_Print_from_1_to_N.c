//link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/B
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void func(int n){
    if(n==0){
        return;
    }
    func(n-1);
    printf("%lld\n",n);
}
int main(){
int n;
scanf("%lld",&n);
func(n);
return 0;
}