#include <stdio.h>

int findLRU(int time[], int f) {
    int min = time[0], pos = 0;
    for(int i=1; i<f; i++)
        if(time[i] < min) { min = time[i]; pos = i; }
    return pos;
}

int main() {
    int f, n, i, j, faults = 0, counter = 0;
    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int ref[n], frame[f], time[f];
    printf("Enter reference string: ");
    for(i=0; i<n; i++) scanf("%d", &ref[i]);

    for(i=0; i<f; i++) frame[i] = -1;

    printf("\nLRU Page Replacement:\n");
    for(i=0; i<n; i++) {
        int hit = 0;

        for(j=0; j<f; j++) {
            if(frame[j] == ref[i]) {
                hit = 1;
                time[j] = ++counter;
            }
        }

        if(!hit) {
            int pos;
            for(j=0; j<f; j++)
                if(frame[j] == -1) { pos = j; goto place; }

            pos = findLRU(time, f);

        place:
            frame[pos] = ref[i];
            time[pos] = ++counter;
            faults++;
        }

        printf("Page %d -> ", ref[i]);
        for(j=0; j<f; j++)
            if(frame[j] == -1) printf("- ");
            else printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
    return 0;
}
