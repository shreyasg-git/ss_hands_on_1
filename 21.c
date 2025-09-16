/*
============================================================================
Name : 21.c
Author : Shreyas Balasaheb Gangurde
Description : 21. Write a program, call fork and print the parent and child process id.
Date: 1st Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid;

  pid = fork();

  if (pid < 0) {
    perror("fork failed");
    return 1;
  } else if (pid == 0) {
    printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
  } else {
    printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
  }

  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton~$ ./a.out
Parent process: PID = 57479, Child PID = 57480
Child process: PID = 57480, Parent PID = 57479

============================================================================
*/