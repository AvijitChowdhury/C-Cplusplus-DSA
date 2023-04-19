#include<stdio.h>
#include<conio.h>j
#include<string.h>
int main(){
char a[100],b[100];
scanf("%s %s",a,b);
int v = strcmp(a,b);
printf("%d",v);//1-> b choto  0->same -1->a choto

if(v<0){printf("A is smaller\n");}
else if(v>0){printf("B is smaller");}
else{printf("Same");}
return 0;
return 0;
}