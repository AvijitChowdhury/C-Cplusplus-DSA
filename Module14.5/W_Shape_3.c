//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/W
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long int
int main(){
    int n;
    scanf("%lld",&n);
    int s=n-1,k=1;
    for(int i=1;i<(2*n+1);i++){
        
        for(int i=0;i<s;i++){
            printf(" ");
        }
        for(int i=0;i<k;i++){
            printf("*");
        }
        printf("\n");
        if(i<=n-1){
        s--;
        k+=2;}
        else if(i==n){

        }
       
        else{
            s+=1;
            k-=2;
        }

    }

return 0;
}