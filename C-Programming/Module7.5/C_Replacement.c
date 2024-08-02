//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/C
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

long long int x = 1e5+10;
long long int a[100000];
int main(){
long long int n,y,cnt=0;
scanf("%lld",&n);
for(long long int i= 0;i<n;i++){scanf("%lld",&a[i]);}
for(long long int i=0 ;i<n;i++){
    if(a[i]<0){
        a[i]=2;
    }else if(a[i]==0){a[i]=0;}
    else{
        a[i]=1;

    }
}
for( long long int i=0 ;i<n;i++){
    printf("%lld ",a[i]);
}

return 0;
}