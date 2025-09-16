/*
============================================================================
Name : 17_2.c
Author : Shreyas Balasaheb Gangurde
Description : 17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 1st Sept, 2025.
============================================================================
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void apply_write_lock(int fd) {
  struct flock lock;
  lock.l_type = F_WRLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0; // Lock entire file
  lock.l_pid = getpid();

  printf("Process %d: Waiting for write lock...\n", getpid());

  if (fcntl(fd, F_SETLKW, &lock) == -1) {
    perror("fcntl");
    exit(EXIT_FAILURE);
  }

  printf("Process %d: Acquired write lock.\n", getpid());
}

void release_lock(int fd) {
  struct flock lock;
  lock.l_type = F_UNLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;

  if (fcntl(fd, F_SETLK, &lock) == -1) {
    perror("unlock");
  } else {
    printf("Process %d: Lock released.\n", getpid());
  }
}

int main() {
  int fd;
  int ticket;

  fd = open("ticket.txt", O_RDWR);
  if (fd == -1) {
    perror("open");
    exit(EXIT_FAILURE);
  }

  apply_write_lock(fd);

  if (read(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
    perror("read");
    release_lock(fd);
    close(fd);
    exit(EXIT_FAILURE);
  }

  printf("Current ticket number: %d\n", ticket);

  ticket++;
  lseek(fd, 0, SEEK_SET);
  if (write(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
    perror("write");
  } else {
    printf("New ticket number: %d\n", ticket);
  }

  sleep(5); // just to test concurrency

  release_lock(fd);
  close(fd);

  return 0;
}

/* OUTPUT
============================================================================



============================================================================
*/