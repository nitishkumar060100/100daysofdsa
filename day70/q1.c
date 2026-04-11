#include <stdio.h>
#include <limits.h>

#define MAX 1000

struct Edge{
    int u,v,w;
}e[MAX];

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);

    int src;
    scanf("%d",&src);

    int dist[MAX];
    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;

    dist[src]=0;

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int u=e[j].u,v=e[j].v,w=e[j].w;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v])
                dist[v]=dist[u]+w;
        }
    }

    for(int j=0;j<m;j++){
        int u=e[j].u,v=e[j].v,w=e[j].w;
        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
            printf("NEGATIVE CYCLE");
            return 0;
        }
    }

    for(int i=0;i<n;i++)
        printf("%d ",dist[i]);

    return 0;
}