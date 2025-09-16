/*
============================================================================
Name : 3.c
Author : Shreyas Balasaheb Gangurde
Description : Write a program to create a file and print the file descriptor
value. Use creat() system call
Date: 1st Sept, 2025.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
    char* filepath = "./temp.txt";

    int fd = creat(filepath, 0644);

    if (fd < 0) {
        perror("Error Creating File");
    } else {
        printf(
            "File Created Successfully. \nThe File Descriptor Value is :: %d "
            "\n",
            fd);
        fflush(stdout);
    }
}

/* OUTPUT
============================================================================
File Created Successfully.
The File Descriptor Value is :: 3
============================================================================
*/