#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
    char a[18];
    //gets(a);
    fgets(a,18,stdin);//take enter input
    printf("%s",a);

return 0;
}