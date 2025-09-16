/*
============================================================================
Name : 14.c
Author : Shreyas Balasaheb Gangurde
Description : 14 Write a program to find the type of a file.
                a. Input should be taken from command line.
                b. program should be able to identify any type of a file.
Date: 1st Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  struct stat data;

  if (lstat(argv[1], &data) < 0) {
    perror("lstat");
    exit(EXIT_FAILURE);
  }

  printf("File: %s\n", argv[1]);
  printf("Type: ");

  if (S_ISREG(data.st_mode))
    printf("Regular file\n");
  else if (S_ISDIR(data.st_mode))
    printf("Directory\n");
  else if (S_ISLNK(data.st_mode))
    printf("Symbolic link\n");
  else if (S_ISCHR(data.st_mode))
    printf("Character device\n");
  else if (S_ISBLK(data.st_mode))
    printf("Block device\n");
  else if (S_ISFIFO(data.st_mode))
    printf("FIFO (named pipe)\n");
  else if (S_ISSOCK(data.st_mode))
    printf("Socket\n");
  else
    printf("Unknown\n");

  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton$ ./a.out temp.txt
File: temp.txt
Type: Regular file
(base) shreyasbg@anton$ ./a.out /dev/pts/0
File: /dev/pts/0
Type: Character device
(base) shreyasbg@anton$ ./a.out /proc/1/cmd
lstat: No such file or directory
(base) shreyasbg@anton$ ./a.out /proc/1/
File: /proc/1/
Type: Directory

============================================================================
*/