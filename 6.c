/*
============================================================================
Name : 6.c
Author : Shreyas Balasaheb Gangurde
Description : 6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 1st Sept, 2025.
============================================================================
*/

#include <errno.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
  char buffer[BUFFER_SIZE];

  ssize_t bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE);

  if (bytesRead > 0) {
    write(STDOUT_FILENO, buffer, bytesRead);
  }

  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton$ ./a.out
HELLO
HELLO

============================================================================
*/