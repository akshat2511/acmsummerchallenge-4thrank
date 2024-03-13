#include <iostream>
#include <stdio.h>

using namespace std;

unsigned long long xor_range(unsigned long long *arr, unsigned long long l, unsigned long long r)
{
    unsigned long long xor_result = 0;
    for (unsigned long long i = l; i < r; i++)
    {
        xor_result ^= arr[i];
    }
    return xor_result;
}
int main()
{
    unsigned long long n;
    cin >> n;
    unsigned long long arr[n];
    for (unsigned long long i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unsigned long long q;
    cin >> q;
    for (unsigned long long i = 0; i < q; i++)
    {
        unsigned long long query_type;
        cin >> query_type;
        if (query_type == 1)
        {
            unsigned long long a, b;
            cin >> a >> b;
            if (b > n)
                b = n;
            if (a < 1)
                a = 1;
            if (1 <= a && a <= b && b <= n)
            {
                unsigned long long xor_result = arr[a-1];
                for (unsigned long long i = a; i < b; i++)
                {
                    xor_result = xor_result ^ arr[i];
                }
                cout << xor_result << endl;
            }
        }
        else if (query_type == 2)
        {
            unsigned long long a, d;
            cin >> a >> d;
            if (1 <= a && a <= n)
            {

                arr[a - 1] ^= d;
            }
        }
        else if (query_type == 3)
        {
            unsigned long long a, b, d;
            cin >> a >> b >> d;
            if (a < 1)
                a = 1;
            if (b > n)
                b = n;
            if (1 <= a && a <= b && b <= n)
            {
                for (unsigned long long j = a - 1; j < b; ++j)
                {
                    arr[j] ^= d;
                }
            }
        }
    }

    return 0;
}
