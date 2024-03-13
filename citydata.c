#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int isArmy;
    struct Node *next;
};
int search(struct Node *head, int value)
{
    struct Node *current = head;

    // Create a hash table
    int hash[1000] = {0};

    while (current != NULL)
    {
        if (hash[current->data] == 1)
        {
            return 1; // Value found, return the node
        }
        hash[current->data] = 1;
        current = current->next;
    }

    return 0; // Value not found
}
struct Node * search1(struct Node *head, int value)
{
    struct Node *current = head;

    while (current != NULL)
    {
        if (current->data == value)
        {
            return current; // Value found, return the node
        }
        current = current->next;
    }

    return NULL; // Value not found
}

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->isArmy = 0;
    newNode->next = NULL;
    return newNode;
}

void addFriend(struct Node **friends, int x, int y)
{
    struct Node *newNodeX = createNode(x);
    struct Node *newNodeY = createNode(y);
    newNodeX->next = friends[y];
    newNodeY->next = friends[x];
    friends[x] = newNodeY;
    friends[y] = newNodeX;
}

void joinArmy(struct Node **friends, int x)
{
    struct Node *curr = friends[x];
    while (curr != NULL)
    {
        curr->isArmy = 1;
        curr = curr->next;
    }
}

void retireFromArmy(struct Node **friends, int x)
{
    friends[x]->isArmy = 0;
}

int getFriendsInArmyCount(struct Node **friends, int x)
{
    int count = 0;
    struct Node *curr = friends[x];
    while (curr != NULL)
    {
        if (curr->isArmy)
        {
            count++;
        }
        curr = curr->next;
    }
    return count;
}
void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        // If the list is empty, set the new node as the head
        *head = newNode;
    }
    else
    {
        // Traverse to the end of the list and insert the new node
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}
void deleteByValue(struct Node** head, int value) {
    if (*head == NULL) {
        return; // Empty list, nothing to delete
    }

    if ((*head)->data == value) {
        // If the value to be deleted is in the head node
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }

    if (current->next != NULL) {
        struct Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}
int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, q;
        scanf("%d %d", &n, &q);

        struct Node *grp[n];
        for (int i = 0; i < n; i++)
        {
            grp[i] = createNode(i + 1);
        }

        while (q--)
        {
            int queryType;
            scanf("%d", &queryType);

            if (queryType == 1)
            {
                int x, y,k;
                scanf("%d %d", &x, &y);
                for (int i = 0; i < n; i++)
                {
                    if (grp[i] != NULL && search(grp[i], x))
                    {k=i;
                        insertAtEnd(&grp[i], y);
                    }
                    if(search(grp[i], y)&&i!=k) deleteByValue(&grp[i],y);
                }
            }
            else if (queryType == 2)
            {
                int x;
                scanf("%d", &x);
                //joinArmy(friends, x);
                for (int i = 0; i < n; i++)
                {
                    search1(grp[i], x)->isArmy=1;

                }

            }
            else if (queryType == 3)
            {
                int x;
                scanf("%d", &x);
               // retireFromArmy(friends, x);
               for (int i = 0; i < n; i++)
                {
                    search1(grp[i], x)->isArmy=0;

                }
            }
            else if (queryType == 4)
            {
                int x;
                int count=0;
                scanf("%d", &x);
                for(int i=0;i<n;i++){
                    if(search(grp[i],x)){
                        struct Node * temp=grp[i]; 
                        while(temp->next!=NULL){
                            if(temp->isArmy==1)count++;
                            temp=temp->next;

                        }
                    }
                }
                printf("%d",count);
            }
        }

        

    }

    return 0;
}
