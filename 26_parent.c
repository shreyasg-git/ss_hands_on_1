/*
============================================================================
Name : 26.c
Author : Shreyas Balasaheb Gangurde
Description : 26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 1st Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Parent: executing child program with argument 'Shreyas'\n");

  execl("./26_child", "26_child", "Shreyas", (char *)NULL);

  perror("execl failed");
  return 1;
}

/* OUTPUT -
============================================================================

(base) shreyasbg@anton~$ cc 26_child.c  -o 26_child
(base) shreyasbg@anton~$ cc 26_parent.c
(base) shreyasbg@anton~$ cc 26_parent.c
(base) shreyasbg@anton~$ ./a.out
Parent: executing child program with argument 'Shreyas'
Child program received input: Shreyas

============================================================================
*/