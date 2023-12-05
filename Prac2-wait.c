#include <stdio.h>
#include <unistd.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("I am the child process.\n");
    } else {
        printf("I am the parent process.\n");
        wait(pid);
        printf("Child process has terminated.\n");
    }
    return 0;
}