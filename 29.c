/*
============================================================================
Name : 29.c
Author : Shreyas Balasaheb Gangurde
Description : 29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 6th Sept, 2025.
============================================================================
*/
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_policy(int policy) {
  switch (policy) {
  case SCHED_OTHER:
    printf("Current policy: SCHED_OTHER (Normal)\n");
    break;
  case SCHED_FIFO:
    printf("Current policy: SCHED_FIFO (Real-time FIFO)\n");
    break;
  case SCHED_RR:
    printf("Current policy: SCHED_RR (Real-time Round-Robin)\n");
    break;
  default:
    printf("Current policy: Unknown\n");
    break;
  }
}

int main() {
  pid_t pid = getpid();
  int policy;

  policy = sched_getscheduler(pid);

  print_policy(policy);

  struct sched_param param;
  param.sched_priority = sched_get_priority_max(SCHED_FIFO);

  if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
    perror("sched_setscheduler to SCHED_FIFO failed");
  } else {
    printf("Scheduling policy changed to SCHED_FIFO\n");
  }

  policy = sched_getscheduler(pid);
  print_policy(policy);

  param.sched_priority = sched_get_priority_max(SCHED_RR);
  if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
    perror("sched_setscheduler to SCHED_RR failed");
  } else {
    printf("Scheduling policy changed to SCHED_RR\n");
  }

  policy = sched_getscheduler(pid);
  print_policy(policy);

  return 0;
}

/* OUTPUT -
============================================================================

(base) shreyasbg@anton~$ sudo ./a.out
[sudo] password for shreyasbg:
Current policy: SCHED_OTHER (Normal)
Scheduling policy changed to SCHED_FIFO
Current policy: SCHED_FIFO (Real-time FIFO)
Scheduling policy changed to SCHED_RR
Current policy: SCHED_RR (Real-time Round-Robin)

============================================================================
*/