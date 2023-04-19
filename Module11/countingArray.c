#include<stdio.h>
#include<conio.h>
int main(){

int n;
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
int cnt[100]={0};
for(int i=0;i<n;i++){
    cnt[a[i]]++;
}
return 0;
}