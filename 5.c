/*
============================================================================
Name : 5.c
Author : Shreyas Balasaheb Gangurde
Description : 5. Write a program to create five new files with infinite loop.
Execute the program in the background and check the file descriptor table at
/proc/pid/fd.
Date: 1st Sept, 2025.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
  char filepath[10] = "0.txt";
  int fds[5];

  printf("PID: %d\n", getpid());

  int i = 0;
  while (i < 5) {
    snprintf(filepath, sizeof(filepath), "%d.txt",
             i); // just lets us use printf styled formatting

    fds[i] = creat(filepath, 0644);
    if (fds[i] < 0) {
      perror("Error Creating File");
    }
    i++;
  }

  while (1)
    ;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton~/Desktop/softwaresystems/HL1 (main)$ ./a.out
PID: 21790

============================================================================
(base) shreyasbg@anton/proc/21790/fd$ ls -l
total 0
lrwx------ 1 shreyasbg shreyasbg 64 Sep  7 02:06 0 -> /dev/pts/0
lrwx------ 1 shreyasbg shreyasbg 64 Sep  7 02:06 1 -> /dev/pts/0
lrwx------ 1 shreyasbg shreyasbg 64 Sep  7 02:06 2 -> /dev/pts/0
l-wx------ 1 shreyasbg shreyasbg 64 Sep  7 02:06 3 -> /home/shreyasbg/Desktop/iiitb_sem1/softwaresystems/HL1/0.txt
l-wx------ 1 shreyasbg shreyasbg 64 Sep  7 02:06 4 -> /home/shreyasbg/Desktop/iiitb_sem1/softwaresystems/HL1/1.txt
l-wx------ 1 shreyasbg shreyasbg 64 Sep  7 02:06 5 -> /home/shreyasbg/Desktop/iiitb_sem1/softwaresystems/HL1/2.txt
l-wx------ 1 shreyasbg shreyasbg 64 Sep  7 02:06 6 -> /home/shreyasbg/Desktop/iiitb_sem1/softwaresystems/HL1/3.txt
l-wx------ 1 shreyasbg shreyasbg 64 Sep  7 02:06 7 -> /home/shreyasbg/Desktop/iiitb_sem1/softwaresystems/HL1/4.txt

============================================================================
*/