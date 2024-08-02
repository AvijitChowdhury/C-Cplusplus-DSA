#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void func(int n){
    if(n==6){return;}
    func(n+1);
    printf("%lld\n",n);
}
int main(){
func(1);
return 0;
}