#include <stdio.h>

#define MAX 10

int main() {
    int n, hungry, pos[MAX];
    int choice;

    printf("Enter the total number of philosophers: ");
    scanf("%d", &n);

    printf("How many are hungry: ");
    scanf("%d", &hungry);

    for (int i = 0; i < hungry; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, n);
        scanf("%d", &pos[i]);
    }

    do {
        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("\nAllow one philosopher to eat at any time\n");

            for (int i = 0; i < hungry; i++) {
                printf("P %d is waiting\n", pos[i]);
            }

            for (int i = 0; i < hungry; i++) {
                printf("P %d is granted to eat\n", pos[i]);
                printf("P %d has finished eating\n", pos[i]);
            }
            break;

        case 2:
            printf("\nAllow two philosophers to eat at the same time\n");

            for (int i = 0; i < hungry; i++) {
                printf("P %d is waiting\n", pos[i]);
            }

            for (int i = 0; i < hungry; i++) {
                // Check if adjacent philosopher exists
                int canEat = 1;
                for (int j = 0; j < hungry; j++) {
                    if (i != j) {
                        if (pos[i] == pos[j] ||
                            pos[i] == pos[j] + 1 ||
                            pos[i] == pos[j] - 1 ||
                            (pos[i] == 1 && pos[j] == n) ||
                            (pos[i] == n && pos[j] == 1)) {
                            canEat = 0;
                        }
                    }
                }

                if (canEat) {
                    printf("P %d is granted to eat\n", pos[i]);
                    printf("P %d has finished eating\n", pos[i]);
                } else {
                    printf("P %d is waiting\n", pos[i]);
                }
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 3);

    return 0;
}
