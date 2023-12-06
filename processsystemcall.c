#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        return EXIT_FAILURE;
    } else if (child_pid == 0) {
        // Child process
        printf("This is the child process with PID: %d\n", getpid());
        printf("Child process exiting...\n");
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("This is the parent process with PID: %d\n", getpid());
        printf("Waiting for child process to finish...\n");
        waitpid(child_pid, &status, 0);
        printf("Child process finished.\n");
    }

    return EXIT_SUCCESS;
}
