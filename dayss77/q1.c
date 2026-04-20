#include <stdio.h>

int n, m;
int adj[1005][1005];
int vis[1005];

void dfs(int u) {
    vis[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] && !vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            printf("NOT CONNECTED");
            return 0;
        }
    }

    printf("CONNECTED");

    return 0;
}