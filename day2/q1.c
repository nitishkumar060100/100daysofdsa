#include <stdio.h>

int main() {
    int n, pos, i;

    // Input the number of elements
    if (scanf("%d", &n) != 1) return 1;
    int arr[n];

    // Input the elements of the array
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    // Input the 1-based position to delete
    if (scanf("%d", &pos) != 1) return 1;

    // Validate the position
    if (pos < 1 || pos > n) {
        // You can add an error message here if needed, 
        // but the problem description implies valid input.
        return 1;
    }

    // Shift elements to the left, overwriting the element at 'pos - 1'
    // Start the shift from the position to be deleted.
    // Continue until the second-to-last element (as the last one is copied over).
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i+1];
    }

    // Print the updated array with n-1 elements
    for (i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i < n - 2) {
            printf(" "); // Print space between elements
        }
    }
    printf("\n"); // Print a newline at the end

    return 0;
}
