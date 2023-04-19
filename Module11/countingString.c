#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
    char s[100];
    scanf("%s",s);
    int cnt[26] = {0};
    for(int i=0;i<strlen(s);i++){
        int value=s[i]-97;
        cnt[value]++;
    }
    for(int i=0;i<26;i++){
        int value = s[i]-97;
        if(cnt[value]!=0){
             printf("%c -> %d\n",i+'a' ,cnt[i]);
        }
        cnt[value]=0;
       
    }

return 0;
}