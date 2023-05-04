#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define int long long
char s[100005];
int is_palindrome(int n)
{
    int low = 0;
    int high = n - 1;

    while (high > low)
    {
        if (s[low++] != s[high--])
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    scanf("%s", &s);

    int n = strlen(s);

    if (is_palindrome(n) == 1)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
    return 0;
}