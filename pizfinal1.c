#include <stdio.h>
#include <stdlib.h> // Add this line for malloc and NULL

struct student
{

    int data;
    struct student *next;
    struct student *prev;

} *head, *temp, *cur;

void push(int data)
{
    temp = (struct student *)malloc(sizeof(struct student));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL)
    {

        head = cur = temp;
    }

    else
    {

        cur->next = temp;
        temp->prev = cur;
        cur = temp;
    }
}

int pop_front()
{
    struct student *anil;
    int d = head->data;

    anil = head;

    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(anil);

    return d;
}

int pop_back()
{
    struct student *anil;
    int d = cur->data;

    anil = cur;
    if (cur == head)
    {

        head = cur = NULL;
        free(anil);
    }
    else
    {
        cur = cur->prev;

        cur->next = NULL;

        free(anil);
    }

    return d;
}

int empty()
{

    if (head == NULL)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

void traverse()
{

    struct student *a;
    a = head;
    while (a != NULL)
    {
        printf("%d ", a->data + 1);
        a = a->next;
    }
    printf("\n");
}
int main()
{
    head = NULL;
    int t, i, n;
    scanf("%d", &t);

    while (t--)
    {

        scanf("%d", &n);
        int demand[n];
        int result[n];
        head = NULL;
        cur = NULL;
        for (i = 0; i < n; i++)
        {

            result[i] = -1;
        }
        for (i = 0; i < n; i++)
        {

            scanf("%d", &demand[i]);
            push(i);

            if (demand[i] == 0)
            {
                // traverse();
                continue;
            }

            else if (demand[i] > 0)
            {

                while ((demand[i]) && !(empty()))
                {

                    result[pop_back()] = i + 1;
                    demand[i]--;
                }

                // traverse();
            }

            else
            {

                while ((demand[i] < 0) && !(empty()))
                {

                    result[pop_front()] = i + 1;

                    demand[i]++;
                }

                // traverse();
            }
        }

        for (i = 0; i < n; i++)
        {

            printf("%d ", result[i]);
        }

        printf("\n");
    }

    return 0;
}