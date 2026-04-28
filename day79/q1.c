#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int v, dist;
} Node;

typedef struct {
    Node arr[MAX * MAX];
    int size;
} MinHeap;

void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

void push(MinHeap *h, int v, int dist) {
    h->arr[h->size].v = v;
    h->arr[h->size].dist = dist;
    int i = h->size;
    h->size++;

    while (i > 0 && h->arr[(i - 1) / 2].dist > h->arr[i].dist) {
        swap(&h->arr[(i - 1) / 2], &h->arr[i]);
        i = (i - 1) / 2;
    }
}

Node pop(MinHeap *h) {
    Node root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;

        if (left < h->size && h->arr[left].dist < h->arr[smallest].dist)
            smallest = left;
        if (right < h->size && h->arr[right].dist < h->arr[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(&h->arr[i], &h->arr[smallest]);
            i = smallest;
        } else break;
    }
    return root;
}

typedef struct Edge {
    int v, w;
    struct Edge* next;
} Edge;

Edge* adj[MAX];

void addEdge(int u, int v, int w) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->v = v;
    e->w = w;
    e->next = adj[u];
    adj[u] = e;

    Edge* e2 = (Edge*)malloc(sizeof(Edge));
    e2->v = u;
    e2->w = w;
    e2->next = adj[v];
    adj[v] = e2;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    int dist[MAX];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[source] = 0;
    push(&h, source, 0);

    while (h.size > 0) {
        Node node = pop(&h);
        int u = node.v;

        if (node.dist > dist[u]) continue;

        Edge* temp = adj[u];
        while (temp) {
            int v = temp->v;
            int w = temp->w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}