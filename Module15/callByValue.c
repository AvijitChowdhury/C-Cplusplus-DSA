#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void fun(int x){
    printf("x er address - %p\n",&x);
    x = 200;
    printf("x er value - %d\n",x);
}
int main(){
int x=10;
fun(x);
printf("x er address - %p\n",&x);
printf("x er value %d\n",x);

return 0;
}