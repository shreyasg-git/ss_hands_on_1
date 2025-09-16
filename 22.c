/*
============================================================================
Name : 22.c
Author : Shreyas Balasaheb Gangurde
Description : 22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 1st Sept, 2025.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int fd;
  pid_t pid;

  fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

  pid = fork();

  if (pid == 0) {
    const char *child_msg = "This is child process.\n";
    write(fd, child_msg, 23);
    printf("Child wrote to file.\n");
  } else {
    const char *parent_msg = "This is parent process.\n";
    write(fd, parent_msg, 24);
    printf("Parent wrote to file.\n");

    wait(NULL);
  }

  close(fd);
  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton$ ./a.out
Parent wrote to file.
Child wrote to file.

============================================================================
*/