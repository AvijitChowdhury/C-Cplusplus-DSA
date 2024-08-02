//problem link: https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/I
#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
    char str[100010];
    scanf("%s",str);

    int l = 0;
    int h = strlen(str) - 1;
    int cnt=1;
    // Keep comparing characters
    // while they are same
    while (h > l) {
        if (str[l++] != str[h--]) {
            cnt=0;
            // will return from here
        }
    }
    

    (cnt)?printf("YES"):printf("NO");
    
  
    return 0;

return 0;
}