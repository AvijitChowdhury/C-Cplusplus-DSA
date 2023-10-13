#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int cntTiger=0,cntpathan=0;
    for(int i=0;i<n;i++){
        int tiger,pathan,;
        scanf("%d",&tiger,&pathan);
        if(tiger>pathan){
            cntTiger++;
        }else{
            cntpathan++;
        }
    }
    if(cntTiger==cntpathan){
        printf("draw");
    }else if(cntTiger>cntpathan){
        printf("Tiger");
    }else{
        printf("Pathan");
    }


return 0;
}