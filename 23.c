/*
============================================================================
Name : 23.c
Author : Shreyas Balasaheb Gangurde
Description : 23. Write a program to create a Zombie state of the running program.
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
    printf("Child process (PID: %d) exiting...\n", getpid());
    exit(0);
  } else {
    printf("Parent process (PID: %d), Child PID: %d\n", getpid(), pid);
    printf("Parent is sleeping... \n");
    sleep(300);
  }

  return 0;
}

/* OUTPUT
============================================================================

// TERMINAL 1

(base) shreyasbg@anton$ ./a.out
Parent process (PID: 58611), Child PID: 58612
Parent is sleeping...
Child process (PID: 58612) exiting...

// TERMINAL 2

(base) shreyasbg@anton$ more /proc/58612/status
Name:	a.out
State:	Z (zombie)


============================================================================
*/