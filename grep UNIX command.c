#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char file[50], word[50], line[200];

    printf("Enter file name: ");
    scanf("%s", file);

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen(file, "r");
    if (!fp) {
        printf("File not found!\n");
        return 1;
    }

    printf("Matching lines:\n");
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word))   // check if word exists in line
            printf("%s", line);
    }

    fclose(fp);
    return 0;
}
