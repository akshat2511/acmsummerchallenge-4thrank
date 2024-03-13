#include <stdio.h>
void bubbleSort(unsigned long int *A, unsigned long int n)
{
    unsigned long int temp;
    unsigned long int isSorted = 0;
    for (unsigned long int i = 0; i < n - 1; i++)
    {
        for (unsigned long int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int main()
{
    unsigned long int num;
    scanf("%lu", &num);
    unsigned long int a[num];
    unsigned long int b[num];
    unsigned long int min = 1000000007;
    unsigned long int mod = 1000000007;
    for (unsigned long int i = 0; i < num; i++)
    {
        scanf("%lu", &a[i]);
    }
    for (unsigned long int i = 0; i < num; i++)
    {
        scanf("%lu", &b[i]);
    }
    bubbleSort(a, num);
    bubbleSort(b, num);
    unsigned long int mul = 1;
    unsigned long int n = 1;
    unsigned long int j = 0;
    while (n <= num)
    {
        for (unsigned long int i = 0; i < num; i++)
        {
            mul =( mul * (a[i] + b[j]))%mod;
            j = (j + 1) % num;
        }
        if (mul < min)
            min = mul;


        mul = 1;
        j = (j + 1) % num;
        n++;
    }
    printf("%lu\n", min);
    /* for(unsigned long int i = 0; i < num; i){
     goto akshat;}*/
}
