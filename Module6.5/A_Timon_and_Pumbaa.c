#include<stdio.h>
#include<conio.h>
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if((a-b)>=0){
        printf("%d",(a-b));
    }
    else{
        printf("%d",0);
    }

return 0;
}