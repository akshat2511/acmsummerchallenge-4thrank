#include <stdio.h>
#include <stdlib.h>

struct node
{
    int *q;
    int order;
};

void insertionSort(struct node **a, int n, int k, char *s)
{
    for (int xm = 0; xm < k; xm++)
    {
        if (s[k - 1 - xm] == '0')
        {
            for (int i = 1; i < n; i++)
            {
                struct node *key = a[i];
                int j = i - 1;
                while (j >= 0 && a[j]->q[k - 1 - xm] > key->q[k - 1 - xm])
                {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = key;
            }
        }
        else if (s[k - 1 - xm] == '1')
        {
            for (int i = 1; i < n; i++)
            {
                struct node *key = a[i];
                int j = i - 1;
                while (j >= 0 && a[j]->q[k - 1 - xm] < key->q[k - 1 - xm])
                {
                    a[j + 1] = a[j];
                    j--;
                }
                a[j + 1] = key;
            }
        }
    }
}

int main()
{
    int n;
    int k;
    scanf("%d %d", &n, &k);

    char s[k + 1];
    scanf("%s", s);

    struct node **a = (struct node **)malloc(n * sizeof(struct node *));
    for (int i = 0; i < n; i++)
    {
        a[i] = (struct node *)malloc(sizeof(struct node));
        a[i]->q = (int *)malloc(k * sizeof(int));
        a[i]->order = i + 1;

        for (int j = 0; j < k; j++)
        {
            scanf("%d", &a[i]->q[j]);
        }
    }

    insertionSort(a, n, k, s);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]->order);
    }

    return 0;
}
