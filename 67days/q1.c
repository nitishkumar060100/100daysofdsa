#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX], vis[MAX], stack[MAX];
int n, m, top = -1;

void dfs(int v){
    vis[v] = 1;
    for(int i = 0; i < n; i++){
        if(adj[v][i] && !vis[i])
            dfs(i);
    }
    stack[++top] = v;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs(i);
    }
    for(int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    return 0;
}