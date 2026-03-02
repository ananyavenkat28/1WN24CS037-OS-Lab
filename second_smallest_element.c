#include <stdio.h>

int main() {
    int n, i, arr[50], first, second;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    first = second = 999999; // large initial values
    for (i = 0; i < n; i++) {
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == 999999)
        printf("No second smallest element.\n");
    else
        printf("Second smallest element = %d\n", second);

    return 0;
}

