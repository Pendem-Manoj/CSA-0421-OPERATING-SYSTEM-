#include <stdio.h>
int main() {
    int b[10], p[10], nb, np, i, j;
    scanf("%d", &nb);
    for(i=0;i<nb;i++) scanf("%d",&b[i]);
    scanf("%d", &np);
    for(i=0;i<np;i++) scanf("%d",&p[i]);

    for(i=0;i<np;i++){
        for(j=0;j<nb;j++)
            if(b[j] >= p[i]) {
                printf("P%d -> Block %d\n", i+1, j+1);
                b[j] = -1;
                break;
            }
        if(j == nb) printf("P%d -> Not Allocated\n", i+1);
    }
}
