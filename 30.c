/*
============================================================================
Name : 30.c
Author : Shreyas Balasaheb Gangurde
Description : 30. Write a program to run a script at a specific time using a Daemon process.
Date: 6th Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid > 0) {
    printf("Daemon process started with PID: %d\n", pid);
    exit(EXIT_SUCCESS);
  }

  umask(0);
  sid = setsid();

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  // starting immediately for now
  while (1) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    if (t->tm_hour == 14 && t->tm_min == 30) {
      system("/home/shreyasbg/Desktop/iiitb_sem1/softwaresystems/HL1/30_script.sh");
      sleep(60);
    }
    sleep(10);
  }

  return 0;
}

/* OUTPUT -
============================================================================

(base) shreyasbg@anton~$ ./a.out
Daemon process started with PID: 64372

============================================================================
*/