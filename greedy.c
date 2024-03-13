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
    int num;
    scanf("%d", &num);
    int a[num];
    int b[num];
    int min = 1000000007;
    int mod = 1000000007;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &b[i]);
    }
    int mul = 1;
    int n = 1;
    int j = 0;
    while (n <= num)
    {
        for (int i = 0; i < num; i++)
        {
            mul = mul * (a[i] + b[j]);
            j = (j + 1) % num;
        }
        
        printf("%d\n", mul);
        mul = 1;
        j = (j + 1) % num;
        n++;
    }
    /* for(int i = 0; i < num; i){
     goto akshat;}*/
}
