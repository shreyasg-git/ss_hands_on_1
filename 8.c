/*
============================================================================
Name : 8.c
Author : Shreyas Balasaheb Gangurde
Description : 8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 1st Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp;
  char buffer[1024];

  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer);
  }

  fclose(fp);
  return 0;
}

/* OUTPUT
============================================================================

(base) shreyasbg@anton$ echo -e "line1\nline2\nline3" > input.txt
(base) shreyasbg@anton$ cc 8.c
(base) shreyasbg@anton$ ./a.out
line1
line2
line3

============================================================================
*/