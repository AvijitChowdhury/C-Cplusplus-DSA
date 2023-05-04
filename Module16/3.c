#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define int long long
int cntNum(int a[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            break;
        }
        cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    scanf("%lld", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    printf("%lld", cntNum(a, n));

    return 0;
}