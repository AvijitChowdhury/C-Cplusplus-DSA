#include<stdio.h>
#include<conio.h>
#include<string.h>
char s[1000010];
int main(){
    scanf("%s",&s);
    int sum=0;
    for(int i=0;i<strlen(s);i++){
        sum+=(int)(s[i]-'0');
    }
    printf("%d",sum);
    

return 0;
}