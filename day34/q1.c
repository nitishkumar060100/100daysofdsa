#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data =