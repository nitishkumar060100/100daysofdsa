#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

int main() {
    int n, i, value;

    struct node *head = NULL, *temp = NULL, *newnode = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value);

        // Step 1: Allocate memory
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = NULL;
        newnode->prev = NULL;

        // Step 2: If list empty
        if(head == NULL) {
            head = newnode;
            temp = newnode;
        }
        else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    // Step 3: Forward Traversal
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}