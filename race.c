#include <stdio.h>
#include <stdlib.h>
#include <float.h>
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // sort left subarray
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}
void MinMax(float arr[], int size, float *min, float *max)
{
    if (size <= 0)
    {
        printf("Array size should be greater than 0.\n");
        return;
    }

    *min = FLT_MAX;
    *max = FLT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < *min)
        {
            *min = arr[i];
        }
        if (arr[i] > *max)
        {
            *max = arr[i];
        }
    }
}
int main()
{
    int num;
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        int temp;
        scanf("%d", &temp);

        int cap[temp];
        int speed[temp];
        float time[temp];
        for (int j = 0; j < temp; j++)
        {
            scanf("%d", &cap[j]);
        }
        for (int j = 0; j < temp; j++)
        {
            scanf("%d", &speed[j]);
        }
        quickSort(speed,0, temp-1);
        quickSort(cap,0, temp-1);

        for (int k = 0; k < temp; k++)
        {
            time[k] = (float)cap[k] / speed[k];
        }
        float min, max;
        MinMax(time, temp, &min, &max);
       // int t = (int)(min + max) / 2;
        printf("%d\n", (int)(min + max) / 2);
    }
}
