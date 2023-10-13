//link: //link: //link: https://codeforces.com/group/MWSDmqGsZm/contest/223339/problem/F
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void func(int a[],int i,int n){
    if(i==n){
        return;
    }
    func(a,i+1,n);
    if(i%2==0){
        printf("%lld ",a[i]);
    }else if(i%2==0 && i==n-1){
    printf("%lld",a[i]);
    }
    
    
}
int main(){
int n;
scanf("%lld",&n);
int a[n];
for(int i=0;i<n;i++){scanf("%lld",&a[i]);}

func(a,0,n);
return 0;
}