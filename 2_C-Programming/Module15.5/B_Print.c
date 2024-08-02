//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/223205/problem/B
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void print(int *n){
    for(int i=1;i<=(long long)*n;i++){
        printf("%lld",i);
        if(i!=*n){
            printf(" ");
        }
    }
}
int main(){
int n;
scanf("%lld",&n);
print(&n);
return 0;
}