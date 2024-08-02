#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define int long long
int x, y;
int add()
{
    return (x + y);
}
int main()
{

    x = 1, y = 2;
    int sum = add();
    printf("%lld", sum);//sum will be 3
    return 0;
}