#include <stdio.h>

int main() {
    int n, i, j, arr[50], count = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break; // count each duplicate once
            }
        }
    }

    printf("Total number of duplicate elements = %d\n", count);
    return 0;
}

