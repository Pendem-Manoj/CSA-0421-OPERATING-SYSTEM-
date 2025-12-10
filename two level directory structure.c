#include <stdio.h>

struct Dir { char user[20]; int f; char files[20][20]; };

int main() {
    int n,i,j;
    printf("Enter number of users: "); scanf("%d",&n);
    struct Dir d[n];

    for(i=0;i<n;i++){
        printf("Username: "); scanf("%s",d[i].user);
        printf("Number of files: "); scanf("%d",&d[i].f);
        for(j=0;j<d[i].f;j++){
            printf("File %d: ",j+1); scanf("%s",d[i].files[j]);
        }
    }

    printf("\nTWO-LEVEL DIRECTORY\n");
    for(i=0;i<n;i++){
        printf("%s: ",d[i].user);
        for(j=0;j<d[i].f;j++) printf("%s ",d[i].files[j]);
        printf("\n");
    }
}
