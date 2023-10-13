//prblem link: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/C
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long int
char a[21],b[21];
int main(){
    scanf("%s %s",a,b);
    if(strcmp(a,b)==-1){
        printf("%s",a);
    }else if(strcmp(a,b)==1){
        printf("%s",b);
    }else{
        printf("%s",a);

    }
    

return 0;
}