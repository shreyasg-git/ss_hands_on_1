/*
============================================================================
Name : 12.c
Author : Shreyas Balasaheb Gangurde
Description : 12. Write a program to find out the opening mode of a file. Use fcntl.
Date: 1st Sept, 2025.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int fd;
  int flgs;

  fd = open("temp.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);

  flgs = fcntl(fd, F_GETFL);

  int accessMode = flgs & O_ACCMODE;
  printf("Access Mode: ");
  if (accessMode == O_RDONLY)
    printf("Read only\n");
  else if (accessMode == O_WRONLY)
    printf("Write only\n");
  else if (accessMode == O_RDWR)
    printf("Read/Write\n");
  else
    printf("Unknown\n");

  if (flgs & O_APPEND)
    printf("Flag: O_APPEND is set\n");
  if (flgs & O_NONBLOCK)
    printf("Flag: O_NONBLOCK is set\n");

  close(fd);
  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton$ ./a.out
Access Mode: Write only
Flag: O_APPEND is set

============================================================================
*/