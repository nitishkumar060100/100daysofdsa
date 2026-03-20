#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insert(int val) {
    heap[size] = val;
    int i = size;
    size++;

    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void heapify(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

void deleteMin() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;
    heapify(0);
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int val;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "delete") == 0) {
            deleteMin();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}