#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {

    int n;
    scanf("%d", &n);

    if(n <= 0)
        return 0;

    struct node *head = NULL, *temp = NULL, *newnode;

    for(int i = 0; i < n; i++) {

        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);

        if(head == NULL) {
            head = temp = newnode;
            newnode->next = head;
        }
        else {
            temp->next = newnode;
            temp = newnode;
            temp->next = head;
        }
    }

    struct node *ptr = head;

    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != head);

    return 0;
}