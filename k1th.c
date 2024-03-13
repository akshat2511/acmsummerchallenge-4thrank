#include <stdio.h>
#include <stdlib.h>
struct node
{
    int *q;
    int order;
};
int main()
{
    int n;
    int k;
    scanf("%d %d", &n, &k);
    char s[k+1];
    scanf("%s", s);
    struct node *a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = (struct node *)malloc(sizeof(struct node));
        {a[i]->q = (int *)malloc(k * sizeof(int));
        a[i]->order = i + 1;
        for (int j = 0; j < k; j++)
        
            scanf("%d", &a[i]->q[j]);
        }
    }

    for (int xm = 0; xm < k; xm++)
    {
       // if (s[k-1-xm] == '0')
        {
            struct node *temp = NULL;

            for (int i = 0; i < n - 1; i++)
            {  
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if ((a[j]->q[k-1-xm]) > (a[j + 1]->q[k-1-xm])&&s[k-1-xm] == '0')
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                     if ((a[j]->q[k-1-xm]) < (a[j + 1]->q[k-1-xm])&&s[k-1-xm] == '1')
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
        }
       /* if (s[k-1-xm] == '1')
        {
            struct node *temp = NULL;

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if ((a[j]->q[k-1-xm]) < (a[j + 1]->q[k-1-xm]))
                    {
                        temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                    }
                }
            }
        }*/
    }
    for(int i = 0; i <n; i++)
    {
        printf("%d ", a[i]->order);
    }
}
