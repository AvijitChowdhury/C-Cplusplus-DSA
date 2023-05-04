#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define int long long
int main()
{
    int n;
    scanf("%lld", &n);
    int s = n - 1, k = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= s; i++)
        {
            printf(" ");
        }
        for (int i = 1; i <= k; i++)
        {
            printf("%lld", k);
        }
        printf("\n");
        if (i <= n)
        {
            s -= 1;
            k += 1;
        }
    }
    return 0;
}