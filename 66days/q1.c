#include <stdio.h>
#include <stdbool.h>

#define MAX 1000

int adj[MAX][MAX], vis[MAX], rec[MAX];
int n, m;

bool dfs(int v){
    vis[v]=1;
    rec[v]=1;
    for(int i=0;i<n;i++){
        if(adj[v][i]){
            if(!vis[i] && dfs(i))
                return true;
            else if(rec[i])
                return true;
        }
    }
    rec[v]=0;
    return false;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfs(i)){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}