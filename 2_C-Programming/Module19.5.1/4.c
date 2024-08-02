#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char s[1000];
int main(){
    scanf("%s",&s);
    long long cntC=0,cntS=0,cnts=0;
    for(long long i=0;i<strlen(s);i++){
        if(s[i]<='Z'&&s[i]>='A'){cntC++;}
        else if(s[i]<='z'&&s[i]>='a'){cntS++;}
        else{
            cnts++;
        }
        printf("Capital - %lld\n Small - %lld\n Spaces - %lld\n",cntC,cntS,cnts);

    }
return 0;
}