#include <stdio.h>

int main()
{
    
    long long int l, r, x;
    long long int n;
    scanf("%lld ", &n);
    long long int a[n];
    for ( int i  = 0; i < n; i++)
    {
        scanf("%lld ", &a[i]);
    }
    long long int b[4];
    for ( int i  = 0; i < 4; i++)
    {
        scanf("%lld ", &b[i]);
    }
   
    for ( int i  = 0; i < b[0]; i++)
    {
    scanf("%lld %lld %lld", &l, &r, &x);
        for ( int i  = l - 1; i < r && i >= 0; i++)
        {
            a[i] = a[i] + x;
        }
    }
    for ( int i  = 0; i < b[1]; i++)
    {
    scanf("%lld %lld %lld", &l, &r, &x);
        for ( int i  = l - 1; i < r && i >= 0; i++)
        {
            a[i] = a[i] - x;
        }
    }
    for ( int i  = 0; i < b[2]; i++)
    {
    scanf("%lld %lld %lld", &l, &r, &x);
        for ( int i  = l - 1; i < r && i >= 0; i++)
        {
            a[i] = a[i] ^ x;
        }
    }
    for ( int i  = 0; i < b[3]; i++)
    {
    scanf("%lld %lld %lld", &l, &r, &x);
        for ( int i  = l - 1; i < r && i >= 0; i++)
        {
            a[i] = (a[i] * x) % 1000000007;
        }
    }
    for ( int i  = 0; i < n; i++)
    {
        printf("%lld ", a[i]);
    }
}