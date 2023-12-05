#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDWR | O_CREAT);
    if (fd == -1) {
        perror("Open failed.\n");
        return 1;
    }

    const char *data = "Hello, world!";
    int bytes_written = write(fd, data, strlen(data));
    if (bytes_written == -1) {
        perror("Write failed.\n");
        close(fd);
        return 1;
    }

    printf("Data written to the file.\n");
    close(fd);
    return 0;
}