#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("Open failed.\n");
        return 1;
    }

    char buffer[1000];
    int bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("Read failed.\n");
        close(fd);
        return 1;
    }

    printf("Content of the file: %s", buffer);
    close(fd);
    return 0;
}