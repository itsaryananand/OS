#include <stdio.h>
#include <unistd.h>

int main() {
    const char *argv[] = {"/bin/sh", "-c", "echo 'Hello, world!'"};
    if (execvp(argv[0], argv) < 0) {
        perror("Exec failed.\n");
    }
    return 0;
}