#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};
int Length(struct Node *p)
{
    int len = 0;

    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node **p, int index, int x)
{
    struct Node *t;
    int i;

    if (index < 0 || index > Length(*p))//
        return;

    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = *p;
        if (*p)
            (*p)->prev = t;
        *p = t;
    }
    else
    {
        struct Node *current = *p;
        for (i = 0; i < index - 1 && current != NULL; i++)
            current = current->next;

        if (current == NULL)
            return;

        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = current;
        t->next = current->next;
        if (current->next)
            current->next->prev = t;
        current->next = t;
    }
}


int Delete(struct Node **p, int index)
{
    int x = -1, i;
    struct Node *q = *p;

    if (index < 1 || index > Length(q))
        return -1;

    if (index == 1)
    {
        *p = (*p)->next;
        if (*p)
            (*p)->prev = NULL;

        x = q->data;
        free(q);
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            q = q->next;
        q->prev->next = q->next;
        if (q->next)
            q->next->prev = q->prev;
        x = q->data;
        free(q);
    }
    return x;
}

int main()
{
    struct Node *A = NULL;
    int testcase, customer = 0;
    int count = 0;
    scanf("%d", &testcase);
    for (int k = 0; k < testcase; k++)
    {
        A = NULL; 
        scanf("%d", &customer);
        int choice[customer + 1];
        int pizzano[customer + 1];

        for (int i = 1; i <= customer; i++)
        {
            scanf("%d", &choice[i]);
            pizzano[i] = -1;
       
            Insert(&A, Length(A), i);
            if (choice[i] > 0)
            {
                for (int j = 1; j <= choice[i]; j++)
                    pizzano[Delete(&A, Length(A))] = i;
            }
            if (choice[i] < 0)
            {
                for (int j = 1; j <= (-1) * (choice[i]); j++)
                    pizzano[Delete(&A, 1)] = i;
            }
        }
        for (int x = 1; x <= customer; x++)
        {
            printf("%d ", pizzano[x]);
        }
        printf("\n");
    }
    return 0;
}