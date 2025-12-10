#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char writeData[] = "Hello OS File System";
    char readData[50];

    printf("Opening file...\n");
    fd = open("demo.txt", O_CREAT | O_RDWR, 0644);

    printf("Writing to file...\n");
    write(fd, writeData, sizeof(writeData));

    printf("Moving file pointer to beginning...\n");
    lseek(fd, 0, SEEK_SET);

    printf("Reading from file...\n");
    read(fd, readData, sizeof(writeData));

    printf("File Content: %s\n", readData);

    printf("Closing file...\n");
    close(fd);

    return 0;
}
