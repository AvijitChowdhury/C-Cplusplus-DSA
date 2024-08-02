#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void add(int *x,int *y){
    *x=10;
    int sum = *x+*y;
    printf("%lld\n",sum);
    printf("value of x is: %lld\n",x);
}
int main(){
int x=2,y=3;
add(&x,&y);
printf("value of x is: %lld\n",x);
return 0;
}