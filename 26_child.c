/*
============================================================================
Name : 26.c
Author : Shreyas Balasaheb Gangurde
Description : 26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 1st Sept, 2025.
============================================================================
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("No input provided!\n");
    return 1;
  }
  printf("Child program received input: %s\n", argv[1]);
  return 0;
}

/* OUTPUT -
============================================================================

// CHECK 26_parent.c

============================================================================
*/