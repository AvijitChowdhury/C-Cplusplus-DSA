//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/F
#include<stdio.h>
#include<conio.h>
#include<string.h>
void func(char *string){
    if(strlen(string)>10){
        printf("%c%d%c\n",string[0],strlen(string)-2,string[strlen(string)-1]);
    }else{
        printf("%s\n",string);
        
    }
}
void solve(int n){

char a[100];

    scanf("%s",&a);
   
    func(a);   

}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        solve(n);
    }
}

