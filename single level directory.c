#include <stdio.h>
#include <string.h>

int main() {
    char dir[20][20], name[20];
    int n = 0, i;

    printf("Enter file name: ");
    scanf("%s", name);

    for(i=0;i<n;i++)
        if(strcmp(dir[i], name) == 0) {
            printf("File already exists!\n");
            return 0;
        }

    strcpy(dir[n++], name);
    printf("File created: %s\n", name);

    printf("\nDirectory:\n");
    for(i=0;i<n;i++)
        printf("%s\n", dir[i]);
}
