#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
int main(){
    int n;
    printf("Give your pattern line number: ");
    scanf("%lld",&n);
    
    int s=n-1,k=1;
    for(int i=1;i<=(2*n)-1;i++){
        for(int j=s;j>=1;j--){
            printf(" ");
        }
        for(int j=1;j<=k;j++){
            printf("*");
        }
        if(i<=n-1){
            s-=1;
            k+=2;
        }else{
            s+=1;
            k-=2;
        }
        printf("\n");

    }

return 0;
}