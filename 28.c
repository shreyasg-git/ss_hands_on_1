/*
============================================================================
Name : 28.c
Author : Shreyas Balasaheb Gangurde
Description : 28. Write a program to get maximum and minimum real time priority.
Date: 6th Sept, 2025.
============================================================================
*/
#include <sched.h>
#include <stdio.h>

int main() {
  int max_priority, min_priority;

  max_priority = sched_get_priority_max(SCHED_FIFO);
  min_priority = sched_get_priority_min(SCHED_FIFO);
  printf("SCHED_FIFO: Max Priority = %d, Min Priority = %d\n", max_priority, min_priority);

  max_priority = sched_get_priority_max(SCHED_RR);
  min_priority = sched_get_priority_min(SCHED_RR);
  printf("SCHED_RR:   Max Priority = %d, Min Priority = %d\n", max_priority, min_priority);

  return 0;
}

/* OUTPUT -
============================================================================

(base) shreyasbg@anton~$ ./a.out
SCHED_FIFO: Max Priority = 99, Min Priority = 1
SCHED_RR:   Max Priority = 99, Min Priority = 1

============================================================================
*/