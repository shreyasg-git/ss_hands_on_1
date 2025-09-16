/*
============================================================================
Name : 13.c
Author : Shreyas Balasaheb Gangurde
Description : 13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 1st Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

int main() {
  fd_set readfds;
  struct timeval timeout;
  int ret;

  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO, &readfds);

  timeout.tv_sec = 10;
  timeout.tv_usec = 0;

  printf("Waiting for input on STDIN (10 seconds)...\n");
  printf("Type something and press Enter:\n");

  ret = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

  if (ret == -1) {
    perror("select");
    exit(1);
  } else if (ret == 0) {
    printf("No data within 10 seconds. Timeout!\n");
  } else {
    if (FD_ISSET(STDIN_FILENO, &readfds)) {
      char buffer[1024];
      int n = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
      if (n > 0) {
        buffer[n] = '\0';
        printf("Done! You entered: %s\n", buffer);
      }
    }
  }

  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton (main)$ ./a.out
Waiting for input on STDIN (10 seconds)...
Type something and press Enter:
yoo
Done! You entered: yoo

(base) shreyasbg@anton (main)$ ./a.out
Waiting for input on STDIN (10 seconds)...
Type something and press Enter:
No data within 10 seconds. Timeout!

============================================================================
*/