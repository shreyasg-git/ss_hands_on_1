/*
============================================================================
Name : 16.c
Author : Shreyas Balasaheb Gangurde
Description : 16. Write a program to perform mandatory locking.
                a. Implement write lock
                b. Implement read lock
Date: 1st Sept, 2025.
============================================================================
*/
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void apply_lock(int fd, short type) {
  struct flock lock;
  lock.l_type = type;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;
  lock.l_pid = getpid();

  if (type == F_UNLCK) {
    if (fcntl(fd, F_SETLK, &lock) == -1) {
      perror("Unlock failed");
    } else {
      printf("Process %d: Lock released\n", getpid());
    }
  } else {
    printf("Process %d: Trying to acquire %s lock...\n", getpid(), (type == F_WRLCK) ? "WRITE" : "READ");

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
      perror("Lock failed");
      exit(EXIT_FAILURE);
    }

    printf("Process %d: Acquired %s lock.\n", getpid(), (type == F_WRLCK) ? "WRITE" : "READ");
  }
}

int main(int argc, char *argv[]) {

  const char *filename = "lock_this_file.txt";

  // Open file in read/write mode
  int fd = open(filename, O_RDWR | O_CREAT, 0644);

  /*
      Mandatory Locking Requirements:
      1. File system mounted with 'mand' option.
      2. File has SGID bit set (chmod g+s) and group execute bit cleared (chmod g-x).
  */

  if (strcmp(argv[1], "r") == 0) {
    apply_lock(fd, F_RDLCK);
    printf("Reading file for 10 seconds...\n");
    sleep(10);
  } else if (strcmp(argv[1], "w") == 0) {
    apply_lock(fd, F_WRLCK);
    printf("Writing to file. Press Enter to unlock...\n");
    getchar();
  } else {
    fprintf(stderr, "Invalid option. Use 'r' for read lock or 'w' for write lock.\n");
    close(fd);
    exit(EXIT_FAILURE);
  }

  apply_lock(fd, F_UNLCK);
  close(fd);

  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton$ touch lock_this_file.txt
(base) shreyasbg@anton$ chmod g+s lock_this_file.txt
(base) shreyasbg@anton$ chmod g-x lock_this_file.txt

(base) shreyasbg@anton$ ls -l lock_this_file.txt
-rw-r-Sr-- 1 shreyasbg shreyasbg 0 Sep  7 20:26 lock_this_file.txt

(base) shreyasbg@anton$ ./a.out w
Process 49355: Trying to acquire WRITE lock...
Process 49355: Acquired WRITE lock.
Writing to file. Press Enter to unlock...

Process 49355: Lock released


// TERMINAL 2

(base) shreyasbg@anton$ ./a.out r
Process 49589: Trying to acquire READ lock...
Process 49589: Acquired READ lock.
Reading file for 10 seconds...
Process 49589: Lock released

============================================================================
*/