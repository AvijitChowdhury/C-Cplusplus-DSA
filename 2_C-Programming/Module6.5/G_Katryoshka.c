#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

int main(){
    long long int e,m,b;
    scanf("%lld%lld%lld",&e,&m,&b);
        long long int ans=0;
    
        if(m<b&&m<e){
             ans=m;
             e-=m;
             b-=m;
            if(e/2<=b){
                ans+=e/2;
            }else if(b*2<=e){
                ans+=b;
            }
        }
        else if(e<m&&e<b){
             ans =e;

        }else if(b<m&&b<e){
            ans =b;
        }
        printf("%lld",ans);
    

return 0;
}