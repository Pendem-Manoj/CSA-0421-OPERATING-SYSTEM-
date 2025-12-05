#include <stdio.h>
#include <limits.h>

int main() {
    int f, n;
    printf("Enter number of frames: ");
    scanf("%d", &f);
    printf("Enter length of reference string: ");
    scanf("%d", &n);

    int ref[n], frame[f];
    printf("Enter reference string:\n");
    for (int i = 0; i < n; i++) scanf("%d", &ref[i]);
    for (int i = 0; i < f; i++) frame[i] = -1;

    int faults = 0;

    printf("\nRef\tFrames\t\tStatus\n");
    for (int i = 0; i < n; i++) {
        int page = ref[i], hit = 0;

        // check hit
        for (int j = 0; j < f; j++)
            if (frame[j] == page) hit = 1;

        if (hit) {
            printf("%d\t", page);
            for (int j = 0; j < f; j++)
                if (frame[j] == -1) printf("- ");
                else printf("%d ", frame[j]);
            printf("\tHit\n");
        }
        else {
            int pos = -1, far = -1;

            // find empty frame
            for (int j = 0; j < f; j++)
                if (frame[j] == -1) { pos = j; break; }

            // if no empty frame → optimal replace
            if (pos == -1) {
                for (int j = 0; j < f; j++) {
                    int k;
                    for (k = i + 1; k < n; k++)
                        if (frame[j] == ref[k]) break;
                    if (k > far) { far = k; pos = j; }
                }
            }
            frame[pos] = page;
            faults++;

            printf("%d\t", page);
            for (int j = 0; j < f; j++)
                if (frame[j] == -1) printf("- ");
                else printf("%d ", frame[j]);
            printf("\tFault\n");
        }
    }

    printf("\nTotal Page Faults = %d\n", faults);
    printf("Total Hits = %d\n", n - faults);
    printf("Hit Ratio = %.2f\n", (float)(n - faults) / n);

    return 0;
}
