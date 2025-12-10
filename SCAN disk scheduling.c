#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, req[20], head, disk, i, j, total = 0;
    
    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for(i = 0; i < n; i++) scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk);

    req[n] = 0;          
    req[n+1] = disk - 1;
    n += 2;
    for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(req[i] > req[j]) {
                int temp = req[i]; req[i] = req[j]; req[j] = temp;
            }

    int pos = 0;
    for(i = 0; i < n; i++) if(req[i] >= head) { pos = i; break; }

    for(i = pos - 1; i >= 0; i--) {
        total += abs(head - req[i]);
        head = req[i];
    }
    for(i = pos; i < n; i++) {
        total += abs(head - req[i]);
        head = req[i];
    }

    printf("Total Head Movement = %d\n", total);
    return 0;
}
