#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define int long long
int add(int *x, int *y)
{
    return (*x + *y);
}
int main()
{

    int x = 1, y = 2;
    int sum = add(&x, &y);
    printf("%lld", sum); // sum will be 3

    return 0;
}