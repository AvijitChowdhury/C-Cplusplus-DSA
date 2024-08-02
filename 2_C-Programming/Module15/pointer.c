#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
int main(){
    int x =100;
    int *ptr = &x;
    printf("x er address - %p\n",&x);
    printf("ptr er value - %p",ptr);
    printf("ptr er value - %p\n",&ptr);
    int y=200;
    printf("y er value - %d\n",x);
    printf("y er value - %d\n",*ptr);

return 0;
}