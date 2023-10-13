//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/T
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long int
int main(){
    int n;
    scanf("%lld",&n);
    int s=n-1,k=1;
    for(int i=0;i<n;i++){
        for(int i=0;i<s;i++){
            printf(" ");
        }
        for(int i=0;i<k;i++){
            printf("*");
        }
        printf("\n");
        s--;
        k+=2;

    }

return 0;
}