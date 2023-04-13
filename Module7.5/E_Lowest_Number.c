//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/D
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

long long int a[100000];
int main(){
long long int n,min=100000,pos=0;
scanf("%lld",&n);
for(long long int i= 0;i<n;i++){scanf("%lld",&a[i]);}
for(long long int i=0 ;i<n;i++){
    if(a[i]<min){
        min=a[i];
        pos=i;        
    }
}
printf("%lld %lld",min,pos+1);

return 0;
}