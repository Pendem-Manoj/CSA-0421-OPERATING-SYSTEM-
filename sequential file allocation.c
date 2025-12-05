#include <stdio.h>

int main() {
    int disk[50], n, start, length;

    // initialize all blocks as free
    for (int i = 0; i < 50; i++)
        disk[i] = 0;

    printf("Enter total number of disk blocks (max 50): ");
    scanf("%d", &n);

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter length of file (number of blocks): ");
    scanf("%d", &length);

    // check if space is available
    int freeFlag = 1;
    for (int i = start; i < start + length; i++) {
        if (i >= n || disk[i] == 1) {
            freeFlag = 0;
            break;
        }
    }

    if (freeFlag) {
        for (int i = start; i < start + length; i++)
            disk[i] = 1;

        printf("\nFile allocated successfully!\n");
        printf("Allocated Blocks: ");
        for (int i = start; i < start + length; i++)
            printf("%d ", i);
    }
    else {
        printf("\nCannot allocate file! Required blocks are not free.\n");
    }

    return 0;
}
