#include <stdio.h>

int time(int *a, int size, int length)
{
    int sum = 0;
    if (size == 1)
    {
        if (a[0] <= length)
            return 0;
        else
            return 1;
    }
    else if (size >1)
    {
        for (int i = 0; i < size-1; i++)
        {

            if (a[i] > length && a[i + 1] <= length) sum = sum + 1;
        }
    }
    return sum;
}

int main()
{
    int n, p, l;
    scanf("%d %d %d", &n, &p, &l); // no of tree
    printf("\n");

    int tree[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tree[i]);
    }
    printf("\n");

    for (int i = 0; i < p; i++)
    {
        int question;
        scanf("%d", &question);
        if (question == 0)
            printf("%d\n", time(tree, n, l));
        else if (question == 1)
        {
            int k, d;
            scanf("%d", &k);
            scanf("%d", &d);
            tree[k - 1] = tree[k - 1] + d;
        }
    }
}