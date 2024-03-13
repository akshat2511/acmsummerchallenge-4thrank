#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *top = NULL;
void push(struct Node **head_ref, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void pop(struct Node **p)
{

    struct Node *temp = *p;
    free(temp);

    *p = (*p)->next;
}
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    struct Node *A = NULL;
    int num, q, id;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        
            scanf("%d", &q);
            if (q == 1)
            {
                scanf("%d", &id);
               
                    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

                    new_node->data = id;
                    new_node->next = (A);
                    (A) = new_node;
                
            }
            else if (q == 2)
            {
                if (isEmpty(A))
                {
                    printf("%d\n", -1);
                }
                else
                {
                    struct Node *temp = A;
                    printf("%d\n", temp->data);
                    A = A->next;
                    free(temp);
                }
            }
            else
                continue;
        
    }
    return 0;
}
