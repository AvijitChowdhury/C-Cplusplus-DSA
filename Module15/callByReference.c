#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void fun(int *x){
    printf("x er value - %d\n",*x);
    *x=200;
    printf("x er value - %p\n",x);

}

int main(){
int x =100;
printf("x er value - %d\n",x);

fun(&x);
printf("x er value - %d\n",x);
return 0;
}