//problem link: 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    long long int n;
    scanf("%lld",&n);
    if(n>0){
        for(long long int i=1;i<=n;i++ ){
            printf("%lld ",i);
        }
    }else if(n==0){
        printf("%d %d",0,1);
    }else{
        printf("%lld",n);
        // n*=(long long int)(-1);
       
       for(long long int i=n;i<=1;i++){
        printf("%lld",i);
       }
      
       }
        
        
    
    return 0;
}
