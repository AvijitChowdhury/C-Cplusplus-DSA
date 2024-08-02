//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/G
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <ctype.h>
 char string[100010];
 int x=32;
int main(){
   
    scanf("%s",string);
    for(int i=0;string[i]!='\0';i++){
        if(isupper(string[i])){
                string[i] |= x;
        }else if(islower(string[i])){
                string[i] =string[i]& ~x;
        }else if(string[i]==','){
            string[i]=' ';
        }
       
    }
 printf("%s",string);
return 0;
}