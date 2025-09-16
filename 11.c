/*
============================================================================
Name : 10.c
Author : Shreyas Balasaheb Gangurde
Description : 11. Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
                    a. use dup
                    b. use dup2
                    c. use fcntl
Date: 1st Sept, 2025.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  int fd1, fd2;
  char *data1 = "Hello from fd1\n";
  char *data2 = "Hello from fd2\n";

  fd1 = open("temp.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

  printf("INITIAL fd: %d\n", fd1);

  // dup
  fd2 = dup(fd1);
  printf("(a) Dup FD: %d\n", fd2);

  write(fd1, data1, strlen(data1));
  write(fd2, data2, strlen(data2));

  close(fd2);

  // dup2 - assign to whatever we want
  int fd3 = dup2(fd1, 10);

  printf("(b) Dup2 FD: %d\n", fd3);

  write(fd3, "Hello from fd3 (dup2)\n", 23);

  close(fd3);

  // fcntl
  int fd4 = fcntl(fd1, F_DUPFD, 20);

  printf("(c) Fcntl FD: %d\n", fd4);

  write(fd4, "Hello from fd4 (fcntl)\n", 24);

  close(fd1);
  close(fd4);

  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton$ ./a.out
INITIAL fd: 3
(a) Dup FD: 4
(b) Dup2 FD: 10
(c) Fcntl FD: 20

(base) shreyasbg@anton$ more temp.txt
Hello from fd1
Hello from fd2
Hello from fd3 (dup2)
Hello from fd4 (fcntl)

============================================================================
*/