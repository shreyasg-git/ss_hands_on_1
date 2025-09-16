/*
============================================================================
Name : 9.c
Author : Shreyas Balasaheb Gangurde
Description : 9. Write a program to print the following information about a given file.
                  a. inode
                  b. number of hard links
                  c. uid
                  d. gid
                  e. size
                  f. block size
                  g. number of blocks
                  h. time of last access
                  i. time of last modification
                  j. time of last change
Date: 1st Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  struct stat fileStat;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  if (stat(argv[1], &fileStat) == -1) {
    perror("stat");
    return 1;
  }

  printf("File: %s\n", argv[1]);
  printf("a. Inode: %lu\n", fileStat.st_ino);
  printf("b. Number of hard links: %lu\n", fileStat.st_nlink);
  printf("c. UID: %u\n", fileStat.st_uid);
  printf("d. GID: %u\n", fileStat.st_gid);
  printf("e. Size: %ld bytes\n", fileStat.st_size);
  printf("f. Block size: %ld bytes\n", fileStat.st_blksize);
  printf("g. Number of blocks: %ld\n", fileStat.st_blocks);
  printf("h. Last access: %s", ctime(&fileStat.st_atime));
  printf("i. Last modification: %s", ctime(&fileStat.st_mtime));
  printf("j. Last status change: %s", ctime(&fileStat.st_ctime));

  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton$ ./a.out src.txt
File: src.txt
a. Inode: 4467065
b. Number of hard links: 2
c. UID: 1000
d. GID: 1000
e. Size: 24 bytes
f. Block size: 4096 bytes
g. Number of blocks: 8
h. Last access: Sun Sep  7 10:39:09 2025
i. Last modification: Sun Sep  7 10:57:11 2025
j. Last status change: Sun Sep  7 10:57:11 2025

============================================================================
*/