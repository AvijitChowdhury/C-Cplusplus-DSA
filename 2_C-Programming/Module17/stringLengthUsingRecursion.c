#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define NULL '\0'
#define int long long
int stringLength(char *s,int i,int cnt){

if(s[i]==NULL){
    return cnt;
}
stringLength(s,++i,++cnt);
}
int main(){
    char s[10];
    scanf("%s",&s);
    int cnt=0;
     int ans=stringLength(s,0,cnt);
     printf("string length: %lld",ans);

return 0;
}