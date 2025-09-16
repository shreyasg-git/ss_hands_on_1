/*
============================================================================
Name : 20.c
Author : Shreyas Balasaheb Gangurde
Description : 20. Find out the priority of your running program. Modify the priority with nice command.
Date: 1st Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
  int priority;
  pid_t pid = getpid();

  priority = getpriority(PRIO_PROCESS, pid);
  if (priority == -1) {
    perror("getpriority");
    return 1;
  }

  printf("PID: %d\n", pid);
  printf("Current nice value: %d\n", priority);

  while (1)
    ;

  return 0;
}

/* OUTPUT
============================================================================

// TERMINAL 1

(base) shreyasbg@anton~$ nice -n 16 ./a.out
PID: 55847
Current nice value: 19

// TERMINAL 2

(base) shreyasbg@anton~$ renice -n 5 -p 55847
renice: failed to set priority for 55847 (process ID): Permission denied
(base) shreyasbg@anton~$ sudo renice -n 5 -p 55847
[sudo] password for shreyasbg:
55847 (process ID) old priority 19, new priority 5

============================================================================
*/