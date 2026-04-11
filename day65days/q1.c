#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int adj[MAX][MAX], visited[MAX];
int n, m;

bool dfs(int v, int parent) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v))
                    return true;
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    if (hasCycle())
        printf("YES");
    else
        printf("NO");
    return 0;
}