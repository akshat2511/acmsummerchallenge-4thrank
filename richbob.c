#include <stdio.h>
#include <stdlib.h>

// Linked list node structure
struct Node
{
    int data;
    struct Node *next;
};

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (i <= j && A[i] <= pivot)
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
    } while (i <= j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, high);
    }
}

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
    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &x);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    struct Node *head = arrayToLinkedList(a, n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] + x / k < 0)
        {
            head = deleteByValue(head, a[i]);
            c++;
        }
    }
    int size;
    int *dec = linkedListToArray(head, &size);
    quickSort(dec, 0, size - 1); // Corrected the end index for quickSort
    int w = (n - c) / k;
    int v = (n - c) % k;
    int delarray[v];
    for (int i = 0; i < v; i++)
    {
        delarray[i] = dec[i];
    }
    for (int j = 0; j < v; j++)
    {
        head = deleteByValue(head, delarray[j]);
    }
    int *finalarray = linkedListToArray(head, &size);
    for (int i = 0; i < size; i++) {
        sum = sum + finalarray[i];
    }

    printf("%d %d\n", w, sum + (w * x));
    int m = 0;
    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < k; j++)
        {
            sum = sum + finalarray[m];
            m++;
        }printf("%d ", sum+x);
        sum=0;
    }

    freeLinkedList(head); // Free the memory used by the linked list

    return 0;
}
