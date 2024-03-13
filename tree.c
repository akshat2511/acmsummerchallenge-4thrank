#include <stdio.h>
#include <stdlib.h>

// Definition for a tree node
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to count the number of nodes at a specific level of the tree
int countNodesAtLevel(struct TreeNode *root, int targetLevel)
{
    if (root == NULL)
    {
        return 0;
    }

    // Queue to perform level-order traversal
    struct QueueNode
    {
        struct TreeNode *node;
        int level;
        struct QueueNode *next;
    };

    // Initialize the queue
    struct QueueNode *front = NULL;
    struct QueueNode *rear = NULL;

    // Enqueue the root node with level 0
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    newNode->node = root;
    newNode->level = 0;
    newNode->next = NULL;
    front = rear = newNode;

    int nodeCount = 0;

    while (front != NULL)
    {
        // Dequeue the current node
        struct QueueNode *current = front;
        front = front->next;

        // Process the node
        if (current->level == targetLevel)
        {
            nodeCount++;
        }

        // Enqueue the left child
        if (current->node->left != NULL)
        {
            newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
            newNode->node = current->node->left;
            newNode->level = current->level + 1;
            newNode->next = NULL;
            if (front == NULL)
            {
                front = newNode;
            }
            else
            {
                rear->next = newNode;
            }
            rear = newNode;
        }

        // Enqueue the right child
        if (current->node->right != NULL)
        {
            newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
            newNode->node = current->node->right;
            newNode->level = current->level + 1;
            newNode->next = NULL;
            if (front == NULL)
            {
                front = newNode;
            }
            else
            {
                rear->next = newNode;
            }
            rear = newNode;
        }

        // Free the memory of the dequeued node
        free(current);
    }

    return nodeCount;
}

// Helper function to create a new tree node
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main()
{
    int max = 0;
    int k;
    int testcase;
    scanf("%d", &testcase);
    for (int i = 0; i < testcase; i++)
    {
        int node;
        scanf("%d", &node);
        struct TreeNode *arr[node];
        for (int j = 0; j < node; j++)
        {
            arr[j] = createNode(j + 1);
        }
        for (int k = 0; k < node - 1; k++)
        {
            int input1, input2;
            scanf("%d", &input1);
            scanf("%d", &input2);
            if (arr[input1 - 1]->left == NULL)
                arr[input1 - 1]->left = arr[input2 - 1];
            else if (arr[input1 - 1]->right == NULL)
                arr[input1 - 1]->right = arr[input2 - 1];
        }
        for (int targetLevel = 0; targetLevel < node; targetLevel++)
        {
            int count = countNodesAtLevel(arr[0], targetLevel);
            if (count > max)
            {
                max = count;
                k = targetLevel;
            }
        }
        printf("%d\n", k + 1);
    }

    // Don't forget to free the memory of the tree nodes when done.
    return 0;
}
