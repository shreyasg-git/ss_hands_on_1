/*
============================================================================
Name : 17_1.c
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

int main() {
  int fd;
  int ticket = 1000;

  fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

  if (write(fd, &ticket, sizeof(ticket)) != sizeof(ticket)) {
    perror("write");
    close(fd);
    exit(EXIT_FAILURE);
  }

  printf("Ticket initialized to %d\n", ticket);
  close(fd);

  return 0;
}

/* OUTPUT
============================================================================

// TERMINAL 1
(base) shreyasbg@anton~$ cc 17_1.c -o init
(base) shreyasbg@anton~$ cc 17_2.c
(base) shreyasbg@anton~$ ./init
Ticket initialized to 1000

// TERMINAL 2
(base) shreyasbg@anton~$ ./a.out
Process 51048: Waiting for write lock...
Process 51048: Acquired write lock.
Current ticket number: 1000
New ticket number: 1001
Process 51048: Lock released.

// TERMINAL 3

(base) shreyasbg@anton~$ ./a.out
Process 51049: Waiting for write lock...
Process 51049: Acquired write lock.
Current ticket number: 1001
New ticket number: 1002
Process 51049: Lock released.




============================================================================
*/