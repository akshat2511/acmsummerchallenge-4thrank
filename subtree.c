#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *a[10]
};
struct TreeNode *createNode(int data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    for (int i; i < 10; i++)
        newNode->a[i] = NULL;
    return newNode;
}
void addToSubtree(struct TreeNode *node, int valueToAdd)
{
    if (node == NULL)
    {
        return;
    }

    node->data += valueToAdd; // Add value to the current node

    // Recursively add value to left and right subtrees
    for (int i; i < 10; i++)
        addToSubtree(node->a[i], valueToAdd);
}
int subtreeSum(struct TreeNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int sum = 0;
for(int i;i<10;i++ )
    sum=sum + subtreeSum(node->a[i]);   // Sum of left subtree
    

    return node->data + sum; // Sum of current node and its subtrees
}

int main()
{
    int max = 0;
    int k;

    int node;
    int query;
    scanf("%d", &node);
    scanf("%d", &query);
    struct TreeNode *arr[node];
    for (int j = 0; j < node; j++)
    {
        int x;
        scanf("%d", &x);
        arr[j] = createNode(x);
    }
    for (int k = 0; k < node - 1; k++)
    {
        int input1, input2;
        scanf("%d", &input1);
        scanf("%d", &input2);
        for(int i;i<10;i++ ){
        if (arr[input1 - 1]->a[i] == NULL)
            arr[input1 - 1]->a[i] = arr[input2 - 1];}
        /*else if (arr[input1 - 1]->right == NULL)
            arr[input1 - 1]->right = arr[input2 - 1];*/
    }
    for (int k = 0; k < query; k++)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int add;
            int val;
            scanf("%d", &add);
            scanf("%d", &val);
            addToSubtree(arr[add - 1], val);
        }
        if (op == 2)
        {
            int add;
            scanf("%d", &add);
            printf("%d\n", subtreeSum(arr[add - 1]));
        }
    }

    return 0;
}
