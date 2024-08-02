#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

long long a[100][100];
int main(){
    long long n;
    scanf("%lld",&n);
    
    long long cnt=0,cnt0=0;
    for(long long i =0;i<n;i++){
        for(long long j=0;j<n;j++){
            long long x;
            scanf("%lld",&x);
            a[i][j]=x;
            
            if(i==j && x==1){
                cnt++;
            }else if(x==0){
                cnt0++;
            }
        }
    }
      

    if(cnt==n&&cnt0==(n*n-n)){
        printf("YES");
    }else{
        printf("NO");
    }

return 0;
}