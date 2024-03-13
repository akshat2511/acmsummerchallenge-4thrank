#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;
// Linked list node structure
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node *arrayToLinkedList(int arr[], int size)
{
    if (size == 0)
    {
        return NULL;
    }

    struct Node *head = createNode(arr[0]);
    struct Node *current = head;

    for (int i = 1; i < size; i++)
    {
        current->next = createNode(arr[i]);
        current = current->next;
    }

    return head;
}
int *linkedListToArray(struct Node *head, int *size)
{
    if (head == NULL)
    {
        *size = 0;
        return NULL;
    }

    // Count the number of elements in the linked list
    int count = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    *size = count;
    int *arr = (int *)malloc(count * sizeof(int));

    // Fill the array with linked list elements
    current = head;
    for (int i = 0; i < count; i++)
    {
        arr[i] = current->data;
        current = current->next;
    }

    return arr;
}
// Function to delete a node by value from the linked list
struct Node *deleteByValue(struct Node *head, int value)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node *current = head;
    struct Node *previous = NULL;

    if (current->data == value)
    {
        head = current->next;
        free(current);
        return head;
    }

    while (current != NULL)
    {
        if (current->data == value)
        {
            previous->next = current->next;
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }

    return head;
}

int main()
{
    int k, x, n, z;
    int sum = 0;
    int c = 0;
    cin >> n >> k >> x;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    struct Node *head = arrayToLinkedList(a, n);
    sort(a, a + n, greater<int>());
    for (int j = 0; j < n; j++)
    {
        printf("%d ", a[j]);
    }
    printf("\n");
    int m = 0;
    for (int i = 0; i <(int)n/k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            sum = sum + a[m];
            m++;
        }
        if (sum < (-1) * x)
        {  
            m = m - k;
            for (int j = 0; j < k; j++)
            {
                head = deleteByValue(head, a[m]);
                m++;
            }
        }
        sum=0;
    }
    sum=0;

    int size;
    int *dec = linkedListToArray(head, &size);
    for (int j = 0; j < size; j++)
    {
        printf("%d ", dec[j]);
    }
     sort(dec, dec + n);
    int w = size / k;
    int v = size % k;
    int delarray[v];
    for (int i = 0; i < v; i++)
    {
        delarray[i] = dec[i];
    }
    for (int j = 0; j < v; j++)
    {
        head = deleteByValue(head, delarray[j]);
    }
    int size1;
    int *finalarray = linkedListToArray(head, &size);
    for (int i = 0; i < size; i++)
    {
        sum = sum + finalarray[i];
    }

    printf("%d %d\n", w, sum + (w * x));
    m = 0;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            sum = sum + finalarray[m];
            m++;
        }
        printf("%d ", sum + x);
        sum = 0;
    }

    return 0;
}
