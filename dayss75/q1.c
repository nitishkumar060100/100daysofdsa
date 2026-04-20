#include <stdio.h>

#define SIZE 200003
#define EMPTY 1000000000000000000LL

long long key[SIZE];
int val[SIZE];
int used[SIZE];

int hash(long long x) {
    long long h = x % SIZE;
    if (h < 0) h += SIZE;
    return (int)h;
}

void insert(long long k, int v) {
    int i = hash(k);
    while (used[i] && key[i] != k) {
        i = (i + 1) % SIZE;
    }
    if (!used[i]) {
        used[i] = 1;
        key[i] = k;
    }
    val[i] = v;
}

int get(long long k, int *found) {
    int i = hash(k);
    while (used[i]) {
        if (key[i] == k) {
            *found = 1;
            return val[i];
        }
        i = (i + 1) % SIZE;
    }
    *found = 0;
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    long long arr[n];
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    long long prefix = 0;
    int maxLen = 0;

    insert(0, -1);

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        int found;
        int idx = get(prefix, &found);

        if (found) {
            int len = i - idx;
            if (len > maxLen) maxLen = len;
        } else {
            insert(prefix, i);
        }
    }

    printf("%d", maxLen);

    return 0;
}