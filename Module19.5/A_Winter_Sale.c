#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
int main(){
double d,p;
scanf("%lf %lf",&d,&p);

int t = 100-d;
float x = (100*p)/t;


 printf("%0.2lf",x);
return 0;
}