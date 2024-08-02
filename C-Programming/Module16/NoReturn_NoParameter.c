#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define int long long
int a[10];
void countEven()
{
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] % 2 == 0)
        {
            cnt++;
        }
    }
    printf("Number of even numbers in array: %lld", cnt);
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%lld", &a[i]);
    }
    countEven();

    return 0;
}