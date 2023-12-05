#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("I am the child process.\n");
    } else if (pid > 0) {
        printf("I am the parent process.\n");
    } else {
        perror("Fork failed.\n");
    }
    return 0;
}