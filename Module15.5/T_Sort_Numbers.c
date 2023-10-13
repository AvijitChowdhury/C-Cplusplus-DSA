//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219158/problem/T
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define int long long
void func(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%lld\n",a[i]);
    }
}
int main(){

int a[3];
int b[3];
for(int i=0;i<3;i++){
    scanf("%lld",&a[i]);
    b[i]=a[i];
    
}
func(a,3);
printf("\n");
for(int i=0;i<3;i++){
    printf("%lld\n",b[i]);
}
return 0;
}