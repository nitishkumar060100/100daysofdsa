#include <stdio.h>

int lowerBound(int a[], int n, int x){
    int l=0,r=n;
    while(l<r){
        int m=(l+r)/2;
        if(a[m]<x) l=m+1;
        else r=m;
    }
    return l;
}

int upperBound(int a[], int n, int x){
    int l=0,r=n;
    while(l<r){
        int m=(l+r)/2;
        if(a[m]<=x) l=m+1;
        else r=m;
    }
    return l;
}

int main(){
    int n,x;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    scanf("%d",&x);
    printf("%d %d",lowerBound(a,n,x),upperBound(a,n,x));
    return 0;
}