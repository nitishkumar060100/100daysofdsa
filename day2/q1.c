#include <stdio.h>
int main(){
int n,pos,i;
scanf("%d",&n);
int a[n];
for(i=0;i<n;i++) scanf("%d",&a[i]);
scanf("%d",&pos);
if(pos<1||pos>n) return 0;
for(i=pos-1;i<n-1;i++) a[i]=a[i+1];
for(i=0;i<n-1;i++) printf("%d ",a[i]);
return 0;
}
