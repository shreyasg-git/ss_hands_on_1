/*
============================================================================
Name : 25.c
Author : Shreyas Balasaheb Gangurde
Description : 25. Write a program to create three child processes. The parent should wait for a particular child (use waitpid system call).
Date: 1st Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  pid_t child_pids[3];

  for (int i = 0; i < 3; i++) {
    pid = fork();

    if (pid == 0) {
      printf("Child %d started with PID: %d\n", i + 1, getpid());
      sleep(2 + i);
      printf("Child %d (PID: %d) exiting\n", i + 1, getpid());
      exit(0);
    } else {
      child_pids[i] = pid;
    }
  }

  printf("Parent waiting for second child (PID: %d)\n", child_pids[1]);
  waitpid(child_pids[1], NULL, 0);
  printf("Parent detected that second child has exited\n");

  for (int i = 0; i < 3; i++) {
    if (i != 1) {
      waitpid(child_pids[i], NULL, 0);
    }
  }

  printf("Parent exiting after all children finished.\n");

  return 0;
}

/* OUTPUT -
============================================================================

(base) shreyasbg@anton~$ ./a.out
Child 1 started with PID: 60024
Parent waiting for second child (PID: 60025)
Child 2 started with PID: 60025
Child 3 started with PID: 60026
Child 1 (PID: 60024) exiting
Child 2 (PID: 60025) exiting
Parent detected that second child has exited
Child 3 (PID: 60026) exiting
Parent exiting after all children finished.


============================================================================
*/