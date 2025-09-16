/*
============================================================================
Name : 4.c
Author : Shreyas Balasaheb Gangurde
Description : 4. Write a program to open an existing file with read write mode.
Try O_EXCL flag also.
Date: 1st Sept, 2025.
============================================================================
*/

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  const char *filepath = "temp2.txt";
  const char *filepath2 = "temp.txt";

  // without O_EXCL - this fails if file doesnt exist
  int fd1 = open(filepath, O_RDWR);
  if (fd1 < 0) {
    printf("open() without O_EXCL failed: %s\n", strerror(errno));
  } else {
    printf("File opened successfully without O_EXCL. FD = %d\n", fd1);
    close(fd1);
  }

  // with O_EXCL
  int fd2 = open(filepath2, O_RDWR | O_CREAT | O_EXCL, 0644);
  if (fd2 < 0) {
    printf("open() with O_EXCL failed: %s\n", strerror(errno));
  } else {
    printf("File opened successfully with O_EXCL. FD = %d\n", fd2);
    close(fd2);
  }

  // O_EXCL means give error if create fails
  // create isnt called if you dont pass O_CREAT
  // open only calls create if O_CREAT is passed.
  // and hence O_EXCL used w/o O_CREAT is useless.

  // open(filepath, O_RDWR); - fails if file doesnt exist
  // open(filepath, O_RDWR | O_CREAT); - will create if donesnt exist but with
  // weird permissions - should give error
  // open(filepath, O_RDWR | O_CREAT, 0644); - does what it needs to

  // open(filepath, O_RDWR | O_CREAT | O_EXCL, 0644); - will give error if
  // file DOES ALREADY EXIST.

  return 0;
}

/* OUTPUT
============================================================================
open() without O_EXCL failed: No such file or directory
File opened successfully with O_EXCL. FD = 3
============================================================================
*/