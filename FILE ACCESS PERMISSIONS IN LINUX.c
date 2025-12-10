#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char line[200], word[50];

    printf("Enter word to search: ");
    scanf("%s", word);

    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("File not found\n");
        return 1;
    }

    while(fgets(line, sizeof(line), fp)) {
        if(strstr(line, word))
            printf("%s", line);
    }

    fclose(fp);
    return 0;
}
