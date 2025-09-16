/*
============================================================================
Name : 27.c
Author : Shreyas Balasaheb Gangurde
Description : 27. Write a program to execute ls -Rl by the following system calls
                  a. execl
                  b. execlp
                  c. execle
Date: 6th Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void use_execl() {
  printf("Executing ls -Rl using execl\n");
  execl("/bin/ls", "ls", "-Rl", (char *)NULL);
  perror("execl failed");
}

void use_execlp() {
  printf("Executing ls -Rl using execlp\n");
  execlp("ls", "ls", "-Rl", (char *)NULL);
  perror("execlp failed");
}

void use_execle() {
  printf("Executing ls -Rl using execle\n");
  char *envp[] = {"HOME=/home", "PATH=/bin:/usr/bin", NULL};
  execle("/bin/ls", "ls", "-Rl", (char *)NULL, envp);
  perror("execle failed");
}

void use_execvp() {
  printf("Executing ls -Rl using execvp\n");
  char *argv[] = {"ls", "-Rl", NULL};
  execvp("ls", argv);
  perror("execvp failed");
}

void use_execv() {
  printf("Executing ls -Rl using execv\n");
  char *argv[] = {"ls", "-Rl", NULL};
  execv("/bin/ls", argv);
  perror("execv failed");
}

int main() {
  int choice;

  printf("1. execl\n2. execlp\n3. execle\n4. execv\n5. execvp\n");
  scanf("%d", &choice);

  switch (choice) {
  case 1:
    use_execl();
    break;
  case 2:
    use_execlp();
    break;
  case 3:
    use_execle();
  case 4:
    use_execvp();
  case 5:
    use_execv();
    break;
  default:
    printf("Invalid choice\n");
  }

  return 0;
}

/* OUTPUT -
============================================================================

(base) shreyasbg@anton~$ ./a.out
Choose exec variant:
1. execl
2. execlp
3. execle
4. execv
5. execvp
1
Executing ls -Rl using execl
.:
total 204
-rw-rw-r-- 1 shreyasbg shreyasbg  1792 Sep  7 20:02 10.c
-rw-rw-r-- 1 shreyasbg shreyasbg  1677 Sep  7 20:02 11.c
-rw-rw-r-- 1 shreyasbg shreyasbg  1205 Sep  7 20:04 12.c
...

(base) shreyasbg@anton~$ ./a.out
Choose exec variant:
1. execl
2. execlp
3. execle
4. execv
5. execvp
2
Executing ls -Rl using execlp
.:
total 204
-rw-rw-r-- 1 shreyasbg shreyasbg  1792 Sep  7 20:02 10.c
-rw-rw-r-- 1 shreyasbg shreyasbg  1677 Sep  7 20:02 11.c
-rw-rw-r-- 1 shreyasbg shreyasbg  1205 Sep  7 20:04 12.c
...

(base) shreyasbg@anton~$ ./a.out
Choose exec variant:
1. execl
2. execlp
3. execle
4. execv
5. execvp
3
Executing ls -Rl using execle
.:
total 204
-rw-rw-r-- 1 shreyasbg shreyasbg  1792 Sep  7 20:02 10.c
-rw-rw-r-- 1 shreyasbg shreyasbg  1677 Sep  7 20:02 11.c
-rw-rw-r-- 1 shreyasbg shreyasbg  1205 Sep  7 20:04 12.c
...

(base) shreyasbg@anton~$ ./a.out
1. execl
2. execlp
3. execle
4. execv
5. execvp
4
Executing ls -Rl using execvp
.:
total 208
-rw-rw-r-- 1 shreyasbg shreyasbg  1792 Sep  7 20:02 10.c
-rw-rw-r-- 1 shreyasbg shreyasbg  1677 Sep  7 20:02 11.c
-rw-rw-r-- 1 shreyasbg shreyasbg  1205 Sep  7 20:04 12.c
...

(base) shreyasbg@anton~$ ./a.out
1. execl
2. execlp
3. execle
4. execv
5. execvp
5
Executing ls -Rl using execv
.:
total 208
-rw-rw-r-- 1 shreyasbg shreyasbg  1792 Sep  7 20:02 10.c
-rw-rw-r-- 1 shreyasbg shreyasbg  1677 Sep  7 20:02 11.c
-rw-rw-r-- 1 shreyasbg shreyasbg  1205 Sep  7 20:04 12.c
...

============================================================================
*/