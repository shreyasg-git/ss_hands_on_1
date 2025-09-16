/*
============================================================================
Name : 10.c
Author : Shreyas Balasaheb Gangurde
Description : 10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
                    a. check the return value of lseek
                    b. open the file with od and check the empty spaces in between the data.
Date: 1st Sept, 2025.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  int fd;
  char data1[10] = "ABCDEFGHIJ";
  char data2[10] = "1234567890";
  off_t offset;

  fd = open("temp.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);

  if (write(fd, data1, 10) != 10) {
    perror("Error writing first data");
    close(fd);
    return 1;
  }

  offset = lseek(fd, 10, SEEK_CUR);

  printf("lseek return value (new offset): %ld\n", (long)offset);

  if (write(fd, data2, 10) != 10) {
    perror("Error writing second data");
    close(fd);
    return 1;
  }

  close(fd);
  return 0;
}

/* OUTPUT - \0 represents empty spaec - null strings
============================================================================

(base) shreyasbg@anton$ ./a.out
lseek return value (new offset): 20
Data written successfully.

(base) shreyasbg@anton$ more temp.txt
ABCDEFGHIJ1234567890

(base) shreyasbg@anton$ od -c temp.txt
0000000   A   B   C   D   E   F   G   H   I   J  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   1   2   3   4   5   6   7   8   9   0
0000036

============================================================================
*/