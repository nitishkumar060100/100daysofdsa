#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[1000][100];
    int count[1000] = {0};
    int size = 0;

    for (int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);

        int found = 0;
        for (int j = 0; j < size; j++) {
            if (strcmp(names[j], temp) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(names[size], temp);
            count[size] = 1;
            size++;
        }
    }

    int maxVotes = 0;
    char winner[100] = "";

    for (int i = 0; i < size; i++) {
        if (count[i] > maxVotes ||
           (count[i] == maxVotes && strcmp(names[i], winner) < 0)) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}