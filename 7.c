/*
============================================================================
Name : 7.c
Author : Shreyas Balasaheb Gangurde
Description : 7. Write a program to copy file1 into file2 ($cp file1 file2).
Date: 1st Sept, 2025.
============================================================================
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    write(STDERR_FILENO, "Usage: cp <source> <destination>\n", 34);
    return 1;
  }

  int src_fd = open(argv[1], O_RDONLY);
  if (src_fd < 0) {
    write(STDERR_FILENO, "Error opening source file\n", 27);
    return 1;
  }

  // O_TRUNC - truncates the file - ignore existing contents so that we can overwrite.
  int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (dest_fd < 0) {
    write(STDERR_FILENO, "Error opening destination file\n", 32);
    close(src_fd);
    return 1;
  }

  char buffer[BUFFER_SIZE];
  ssize_t bytesRead;

  while ((bytesRead = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
    if (write(dest_fd, buffer, bytesRead) != bytesRead) {
      write(STDERR_FILENO, "Write error\n", 12);
      close(src_fd);
      close(dest_fd);
      return 1;
    }
  }

  close(src_fd);
  close(dest_fd);
  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton$ echo "HELLO" > src.txt
(base) shreyasbg@anton$ ./a.out src.txt dest.txt
(base) shreyasbg@anton$ more dest.txt
HELLO

============================================================================
*/