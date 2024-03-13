#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
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
    if(1<=num<=100){
    for (int i = 0; i < num; i++)
    {
        int temp;
        scanf("%d", &temp);
        if(3<=temp<=100){
        int a[temp];
        for (int j = 0; j < temp; j++)
        {int x;
            scanf("%d", &x);
            a[j] =abs(x);
        }
        printf("\n");
        bubbleSort(a,temp);
        int x=a[0];
        int y=a[1];
        int xm=1;
        akshat:
        if(y==0)
        {
            y=a[1+xm++];
            goto akshat;
            break;
        }
        printf("%d",x+y);

    }
    }
    }
}