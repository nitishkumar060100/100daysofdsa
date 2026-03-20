#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int dq[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
        dq[front] = x;
    } else if (front > 0) {
        dq[--front] = x;
    }
}

void push_back(int x) {
    if (front == -1) {
        front = rear = 0;
        dq[rear] = x;
    } else {
        dq[++rear] = x;
    }
}

void pop_front() {
    if (isEmpty()) return;
    if (front == rear) front = rear = -1;
    else front++;
}

void pop_back() {
    if (isEmpty()) return;
    if (front == rear) front = rear = -1;
    else rear--;
}

int getFront() {
    if (isEmpty()) return -1;
    return dq[front];
}

int getBack() {
    if (isEmpty()) return -1;
    return dq[rear];
}

void clear() {
    front = rear = -1;
}

void reverse() {
    if (isEmpty()) return;
    int i = front, j = rear;
    while (i < j) {
        int t = dq[i];
        dq[i] = dq[j];
        dq[j] = t;
        i++;
        j--;
    }
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void sortDeque() {
    if (isEmpty()) return;
    qsort(dq + front, size(), sizeof(int), cmp);
}

int main() {
    int n, x;
    scanf("%d", &n);

    char op[20];

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        } else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        } else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        } else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        } else if (strcmp(op, "front") == 0) {
            printf("%d\n", getFront());
        } else if (strcmp(op, "back") == 0) {
            printf("%d\n", getBack());
        } else if (strcmp(op, "empty") == 0) {
            printf("%d\n", isEmpty());
        } else if (strcmp(op, "size") == 0) {
            printf("%d\n", size());
        } else if (strcmp(op, "clear") == 0) {
            clear();
        } else if (strcmp(op, "reverse") == 0) {
            reverse();
        } else if (strcmp(op, "sort") == 0) {
            sortDeque();
        }
    }

    if (!isEmpty()) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", dq[i]);
        }
    }

    return 0;
}