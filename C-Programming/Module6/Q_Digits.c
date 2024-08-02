//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219432/problem/Q

#include<stdio.h>
#include<conio.h>
#include<string.h>

void solve(int a){
    do{
        printf("%d ",a%10); 
        a/=10;     
    }while(a!=0);
    printf("\n");
}
int main(){
    int t;
    scanf("%d",&t);  
    while(t--){
        int x;
        scanf("%d",&x);
        solve(x);
    }
return 0;
}