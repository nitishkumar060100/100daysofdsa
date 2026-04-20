#include <stdio.h>

#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[1005][1005];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        if (w < adj[u][v]) {
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }

    int key[1005];
    int vis[1005] = {0};

    for (int i = 1; i <= n; i++) {
        key[i] = INF;
    }

    key[1] = 0;

    int total = 0;

    for (int i = 1; i <= n; i++) {
        int u = -1;
        int min = INF;

        for (int v = 1; v <= n; v++) {
            if (!vis[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        vis[u] = 1;
        total += key[u];

        for (int v = 1; v <= n; v++) {
            if (adj[u][v] < key[v] && !vis[v]) {
                key[v] = adj[u][v];
            }
        }
    }

    printf("%d", total);

    return 0;
}