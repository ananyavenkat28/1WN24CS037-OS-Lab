#include <stdio.h>

int main() {
    int n, i, j, mat[20][20], sum = 0;
    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    for (i = 0; i < n; i++)
        sum += mat[i][i]; // left diagonal

    printf("Sum of left diagonal = %d\n", sum);
    return 0;
}

