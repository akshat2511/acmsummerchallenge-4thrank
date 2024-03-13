#include <stdio.h>
#include <stdlib.h>

struct Node {
    unsigned long data;
    struct Node* next;
};

struct Node* createNode(unsigned long data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, unsigned long data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(struct Node** head, unsigned long value) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == value) {
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

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%lu ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeLinkedList(struct Node** head) {
    struct Node* current = *head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
}

unsigned long search(struct Node* head, unsigned long value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1; // Value found
        }
        current = current->next;
    }
    return 0; // Value not found
}

unsigned long main() {
    unsigned long n, q;
    scanf("%lu", &n);
    scanf("%lu", &q);
    
    struct Node* list[n];

    for (unsigned long i = 0; i < n; i++) {
        list[i] = NULL;  // Initialize each list to NULL
        insertEnd(&list[i], i + 1);
    }

    for (unsigned long i = 0; i < q; i++) {
        char op[3];
        scanf("%s", op);  // Use %s to read a string
        
        if (op[0] == '+') {
            unsigned long a, b;
            scanf("%lu", &a);
            scanf("%lu", &b);
            for (unsigned long i = 0; i < n; i++) {
                if (search(list[i], b))
                    deleteNode(&list[i], b);
                

                if (search(list[i], a))
                    insertEnd(&list[i], b);
             
            }
        }
        if (op[0] == '-') {
            unsigned long a;
            scanf("%lu", &a);
            for (unsigned long i = 0; i < n; i++) {
                if (search(list[i], a)) {
                    deleteNode(&list[i], a);
                    
                }
            }
            for (unsigned long i = 0; i < n; i++) {
                    if(list[i]==NULL){
                    insertEnd(&list[i], a);
                    break;
                
            }}
        }
        if (op[0] == '?') {
            unsigned long flag = 0;
            unsigned long a, b;
            scanf("%lu", &a);
            scanf("%lu", &b);
            for (unsigned long i = 0; i < n; i++) {
                if (search(list[i], a) && search(list[i], b)){
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                printf("YES\n");
            else
                printf("NO\n");
        }
        
      
    }

    

    return 0;
}
