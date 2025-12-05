#include <stdio.h>

int main() {
    int f, n, i, j, pos = 0, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d",&f);
    printf("Enter number of pages: ");
    scanf("%d",&n);

    int ref[n], frame[f];
    printf("Enter reference string: ");
    for(i=0;i<n;i++) scanf("%d",&ref[i]);
    for(i=0;i<f;i++) frame[i] = -1;

    printf("\nFIFO Page Replacement:\n");
    for(i=0;i<n;i++) {
        int hit = 0;
        for(j=0;j<f;j++)
            if(frame[j] == ref[i]) hit = 1;

        if(!hit) {
            frame[pos] = ref[i];
            pos = (pos + 1) % f;
            faults++;
        }

        printf("Page %d -> ", ref[i]);
        for(j=0;j<f;j++) printf("%d ", frame[j]);
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);
}
