#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX], indeg[MAX], q[MAX];
int n, m;

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u][v]=1;
        indeg[v]++;
    }
    int front=0,rear=0;
    for(int i=0;i<n;i++)
        if(indeg[i]==0)
            q[rear++]=i;
    int cnt=0;
    while(front<rear){
        int u=q[front++];
        printf("%d ",u);
        cnt++;
        for(int i=0;i<n;i++){
            if(adj[u][i]){
                indeg[i]--;
                if(indeg[i]==0)
                    q[rear++]=i;
            }
        }
    }
    if(cnt!=n)
        printf("Cycle");
    return 0;
}