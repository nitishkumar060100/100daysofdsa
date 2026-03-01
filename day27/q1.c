#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newnode;
    
    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->link = NULL;

        if(head == NULL) {
            head = temp = newnode;
        }
        else {
            temp->link = newnode;
            temp = newnode;
        }
    }
    return head;
}

int getLength(struct node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->link;
    }
    return count;
}

void findIntersection(struct node *head1, struct node *head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->link;
    }
    else {
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->link;
    }

    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 == ptr2) {
            printf("%d", ptr1->data);
            return;
        }
        ptr1 = ptr1->link;
        ptr2 = ptr2->link;
    }

    printf("No Intersection");
}

int main() {

    int n, m;

    scanf("%d", &n);
    struct node *head1 = createList(n);

    scanf("%d", &m);
    struct node *head2 = createList(m);

    struct node *temp1 = head1;
    for(int i = 1; i < 2; i++)
        temp1 = temp1->link;

    struct node *temp2 = head2;
    while(temp2->link != NULL)
        temp2 = temp2->link;

    temp2->link = temp1;

    findIntersection(head1, head2);

    return 0;
}