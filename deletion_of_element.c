#include <stdio.h>

int main() {
    int n, i, pos, arr[50];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter position to delete (1-%d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
    } else {
        for (i = pos - 1; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;

        printf("Array after deletion: ");
        for (i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
    }

    return 0;
}

