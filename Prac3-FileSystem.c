#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("Open failed");
        return 1;
    }

    char buffer[100] = "Hello, world!";
    int bytes_written = write(fd, buffer, sizeof(buffer));
    if (bytes_written == -1) {
        perror("Write failed");
        close(fd);
        return 1;
    }

    lseek(fd, 0, SEEK_SET);

    char read_buffer[100];
    int bytes_read = read(fd, read_buffer, sizeof(read_buffer));
    if (bytes_read == -1) {
        perror("Read failed");
        close(fd);
        return 1;
    }

    printf("Data read from the file: %s\n", read_buffer);

    close(fd);
    return 0;
}