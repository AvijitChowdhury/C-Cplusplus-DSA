#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define int long long
int a[10];
void countNegative(int a[])
{
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] < 0)
        {
            cnt++;
        }
    }
    printf("count of negative numbers: %lld", cnt);
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        scanf("%lld", &a[i]);
    }
    countNegative(a);

    return 0;
}