#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    scanf("%d", &n);

    int *queue = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    scanf("%d", &m);

    m = m % n;

    int front = m;
    int rear = (n - 1 + m) % n;

    int count = n;

    for (i = 0; i < count; i++) {
        printf("%d ", queue[(front + i) % n]);
    }

    free(queue);
    return 0;
}