#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process
        printf("Child process started (PID: %d)\n", getpid());
        exit(0);  // Child exits immediately
    } else {
        // Parent process
        printf("Parent process (PID: %d), child PID: %d\n", getpid(), pid);
        printf(
            "Sleeping for 30 seconds. During this time, child becomes "
            "zombie.\n");
        sleep(30);  // Parent sleeps, child is already dead
        printf("Parent exiting now.\n");
    }

    return 0;
}
