/*
============================================================================
Name : 19.c
Author : Shreyas Balasaheb Gangurde
Description : 19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 1st Sept, 2025.
============================================================================
*/
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

// this function is taken from chatgpt
static __inline__ unsigned long long rdtsc(void) {
  unsigned int hi, lo;
  __asm__ volatile("rdtsc" : "=a"(lo), "=d"(hi));
  return ((unsigned long long)hi << 32) | lo;
}

int main() {
  unsigned long long start, end;
  pid_t pid;

  start = rdtsc();
  pid = getpid();
  end = rdtsc();

  printf("PID: %d\n", pid);
  printf("Cycles taken: %llu\n", end - start);

  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton~$ ./a.out
PID: 55358
Cycles taken: 13628

============================================================================
*/