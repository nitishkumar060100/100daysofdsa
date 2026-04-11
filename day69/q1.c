#include <stdio.h>
#include <limits.h>

#define MAX 1000

int adj[MAX][MAX], n, m;

int minDist(int dist[], int vis[]){
    int min = INT_MAX, idx = -1;
    for(int i = 0; i < n; i++){
        if(!vis[i] && dist[i] < min){
            min = dist[i];
            idx = i;
        }
    }
    return idx;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        adj[u][v]=w;
    }
    int src;
    scanf("%d",&src);

    int dist[MAX], vis[MAX]={0};

    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;

    dist[src]=0;

    for(int i=0;i<n;i++){
        int u=minDist(dist,vis);
        if(u==-1) break;
        vis[u]=1;
        for(int v=0;v<n;v++){
            if(adj[u][v] && !vis[v] && dist[u]!=INT_MAX &&
               dist[u]+adj[u][v]<dist[v]){
                dist[v]=dist[u]+adj[u][v];
            }
        }
    }

    for(int i=0;i<n;i++)
        printf("%d ",dist[i]);

    return 0;
}