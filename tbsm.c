#include <stdio.h>

unsigned long gcd(unsigned long a, unsigned long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

unsigned long lcm(unsigned long start, unsigned long end)
{
    unsigned long lcm = start;

    for (unsigned long i = start + 1; i <= end; i++)
    {
        lcm = (lcm * i) / gcd(lcm, i);
    }

    return lcm;
}
int findfactors(unsigned long a, int b){
    int count = 0;
    akshat:
    if(a%b == 0&&a>1){
        count++;
        a=a/b;
        goto akshat;

    }
    return count;
}

int main()
{
    unsigned long start, end, n;
    scanf("%lu", &start);
    scanf("%lu", &end);
    scanf("%lu", &n);
    unsigned long result = lcm(start, end);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%lu", &x);
        printf("%lu ",findfactors(result,x));
    }
//printf("\n%lu ",result);
    return 0;
}
