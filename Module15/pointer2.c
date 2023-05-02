#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
int main(){
double x= 5.25;
double *ptr = &x;

printf("x er value - %0.2lf\n",x);
printf("x er value - %0.2lf\n",*ptr);
printf("size of ptr - %d",sizeof(ptr));
return 0;
}