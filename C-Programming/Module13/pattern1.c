#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long 
int main(){
    int n;
    printf("Give the number of lines for your pattern: ");
    scanf("%lld",&n);
   
    for(int i=1;i<=n;i++){
        for(int j=n-1;j>=i;j--){
            printf(" ");
            
        }

        for(int j=1;j<=i;j++){
            printf("*");
        }
        
        for(int k=2;k<=i;k++){
            printf("*");
        }
        printf("\n");
    }

return 0;
}
/*
ouput:
    *
   ***
  *****
 *******
*********


*/