//problemlink: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/J
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
// #define int long long 
char s[10000000];
int main(){
    scanf("%s",&s);
    int a[26]={0};
    for(int i=0;s[i]!='\0';i++){
        a[(int)(s[i]-'a')]+=1;
    }
    for(int i=0;i<26;i++){
        if(a[i]!=0){
        printf("%c : %d\n",i+'a',a[i]);
    }}
    

return 0;
}