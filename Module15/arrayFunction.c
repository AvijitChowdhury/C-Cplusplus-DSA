#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void fun(int *ar,int n){
    for(int i=0;i<n;i++){
        printf("%d ",ar[i]);
    }
}
int main(){
int ar[]={1,2,3,4,5};
fun(ar,5);
return 0;
}