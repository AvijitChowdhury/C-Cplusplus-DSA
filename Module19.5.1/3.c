#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

long long a[100][100];
int main(){
    long long r,c;
    scanf("%lld %lld",&r,&c);
    
    
    for(long long i =0;i<r;i++){
        for(long long j=0;j<c;j++){
            long long x;
            scanf("%lld",&x);
            a[i][j]=x;
                 
        }
    }
      

    
    for(int j=0;j<c;j++){
        printf("%lld ",a[r-1][j]);
    }
    printf("\n");
    for(int i=0;i<r;i++){
        printf("%lld ",a[i][c-1]);
    }
return 0;
}