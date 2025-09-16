/*
============================================================================
Name : 24.c
Author : Shreyas Balasaheb Gangurde
Description : 24. Write a program to create an orphan process.
Date: 1st Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid;

  pid = fork();

  if (pid == 0) {
    sleep(5);
    printf("Child process (PID: %d) running. Parent PID = %d\n", getpid(), getppid());
    printf("Child is now orphan and adopted by init/systemd.\n");
  } else {
    printf("Parent process (PID: %d) exiting...\n", getpid());
    exit(0);
  }

  return 0;
}

/* OUTPUT - demonstrates early return - causes a problem
============================================================================

// TERMINAL 1
(base) shreyasbg@anton~$ ./a.out
Parent process (PID: 59417) exiting...
(base) shreyasbg@anton~$ Child process (PID: 59418) running. Parent PID = 4931
Child is now orphan and adopted by init/systemd.


============================================================================
*/